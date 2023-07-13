//
// Created by JoachimWagner on 13.07.2023.
//

#pragma once
#include "../../abstract_vector_factory.h"
#include "../../../generators/generator_factory.h"
#include <algorithm>
#include <execution>

namespace atlas::collections {

    template<class T>
    class vector_factory_parallel_auto_impl : public abstract_vector_factory<T>{
        using MyGeneratorFactory =  std::unique_ptr<atlas::generators::generator_factory<T>>;
        MyGeneratorFactory generator_factory_;


    public:
        explicit vector_factory_parallel_auto_impl(MyGeneratorFactory generatorFactory, size_t dummy) : generator_factory_(std::move(generatorFactory)) {}
        ~vector_factory_parallel_auto_impl()  override = default;
    protected:
        auto fill_vector() -> void override {
            auto generator_ = generator_factory_->create();
            auto field = this->getData();
            std::for_each(std::execution::par, this->getData()->begin(), this->getData()->end(),[&generator_](T &value){
                value = generator_->next();
            });
        }

    };

}