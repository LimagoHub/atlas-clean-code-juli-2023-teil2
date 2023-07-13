//
// Created by JoachimWagner on 13.07.2023.
//

#pragma once
#include <iostream>
#include "abstract_vector_factory_decorator.h"
#include "../../../time/impl/stopwatch_impl.h"
namespace atlas::collections {



    template<class T>
    class vector_factory_benchmark_decorator: public abstract_vector_factory_decorator<T>{
        atlas::times::stopwatch_impl stopwatch;

    public:

        explicit vector_factory_benchmark_decorator(VectorFactoryPointer vectorFactory)
                : abstract_vector_factory_decorator(std::move(vectorFactory)) {}

        ~vector_factory_benchmark_decorator() override = default;

        auto create_and_fill_vector(size_t size) -> VectorPointer override {
            stopwatch.start();
            auto result=  vectorFactory->create_and_fill_vector(size);
            stopwatch.stop();
            std::cout << "Duration = " << stopwatch.elapsedDuration().count() << " .ms" << std::endl;
            return result;
        }
    };
}
