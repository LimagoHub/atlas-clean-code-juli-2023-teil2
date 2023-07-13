//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once

#include <cmath>
#include "../../abstract_vector_factory.h"
#include "../../../generators/generator_factory.h"
#include <vector>
#include <thread>
namespace atlas::collections {

    template<class T>
    class vector_factory_parallel_impl : public abstract_vector_factory<T>{
        using MyGeneratorFactory =  std::unique_ptr<atlas::generators::generator_factory<T>>;
        MyGeneratorFactory generator_factory_;
        size_t threadCount_;
        size_t partitionSize_;
        std::vector<std::thread> threadHolder_;
    public:
        explicit vector_factory_parallel_impl(MyGeneratorFactory generator_factory, size_t threadCount)
            : generator_factory_(std::move(generator_factory)), threadCount_(threadCount) {}
        ~vector_factory_parallel_impl()  override = default;
    protected:


        auto fill_vector() -> void override {
            calculatePartitionSize();
            intializeThreads();
            startWorker();
            joinThreads();
        }
    private:
        auto calculatePartitionSize() -> void {
            partitionSize_ = static_cast<std::size_t>(std::floor(this->getSize() / threadCount_));
        }

        void intializeThreads() {
            threadHolder_.reserve(threadCount_);
        }

        auto startWorker() -> void {
            for (auto segment = 0U; segment < threadCount_; ++segment) {
                start_single_worker_for_segment( segment);
            }
        }

        auto  start_single_worker_for_segment( const unsigned int segment) -> void
        {
            const size_t start = segment * partitionSize_;
            const size_t end = start + partitionSize_;
            threadHolder_.emplace_back(
                    &vector_factory_parallel_impl::fill_segment_worker,
                    this,
                    start,
                    end);
        }



        auto joinThreads() -> void
        {
            for (auto& thread : threadHolder_) {
                thread.join();
            }
        }

        auto fill_segment_worker( const std::size_t startIndex, const std::size_t endIndex) -> void
        {
            auto const generator = generator_factory_->create();
            auto field = this->getData();
            for (auto i = startIndex; i < endIndex; ++i) {
                field->at(i) = generator->next();
            }
        }

    };

}
