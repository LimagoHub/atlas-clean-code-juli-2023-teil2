//
// Created by JoachimWagner on 13.07.2023.
//

#pragma once



#pragma once
#include <iostream>
#include "../../vector_factory.h"
#include "../../../time/impl/stopwatch_impl.h"
namespace atlas::collections {



    template<class T>
    class abstract_vector_factory_decorator: public vector_factory<T>{

    protected:
        using VectorFactoryPointer = std::unique_ptr<atlas::collections::vector_factory<T>>;
        using VectorPointer = std::shared_ptr<std::vector<T>>;



        VectorFactoryPointer vectorFactory;


    public:
        explicit abstract_vector_factory_decorator(VectorFactoryPointer vectorFactory) : vectorFactory(
                std::move(vectorFactory)) {}

        ~abstract_vector_factory_decorator() override = default;


    };
}

