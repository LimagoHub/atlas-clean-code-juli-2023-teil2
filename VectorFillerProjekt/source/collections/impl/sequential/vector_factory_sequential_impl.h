//
// Created by JoachimWagner on 05.07.2023.
//

#pragma once
#include "../../abstract_vector_factory.h"
#include "../../../generators/generator.h"

namespace atlas::collections {

    template<class T>
    class vector_factory_sequential_impl : public abstract_vector_factory<T>{
        using MyGenerator =  std::unique_ptr<atlas::generators::generator<T>>;
        MyGenerator generator_;


    public:
        explicit vector_factory_sequential_impl(MyGenerator generator) : generator_(std::move(generator)) {}
        ~vector_factory_sequential_impl()  override = default;
    protected:
        auto fill_vector() -> void override {
            auto field = this->getData();
            for (size_t i = 0; i < this->getSize(); ++i) {
                field->at(i) = generator_->next();
            }
        }

    };

}
