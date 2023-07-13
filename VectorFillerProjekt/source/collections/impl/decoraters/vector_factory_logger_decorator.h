//
// Created by JoachimWagner on 13.07.2023.
//

#pragma once
#include <iostream>
#include "abstract_vector_factory_decorator.h"
#include "../../../time/impl/stopwatch_impl.h"
namespace atlas::collections {



    template<class T>
    class vector_factory_logger_decorator: public abstract_vector_factory_decorator<T>{

    public:

        explicit vector_factory_logger_decorator(VectorFactoryPointer vectorFactory)
                : abstract_vector_factory_decorator(std::move(vectorFactory)) {}

        ~vector_factory_logger_decorator() override = default;

        auto create_and_fill_vector(size_t size) -> VectorPointer override {

            std::cout << "create_and_fill_vector wurde gerufen" << std::endl;
            return  vectorFactory->create_and_fill_vector(size);

        }
    };
}
