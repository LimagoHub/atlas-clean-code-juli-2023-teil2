//
// Created by JoachimWagner on 12.07.2023.
//

#pragma once
#include <memory>
#include <iostream>
#include "../collections/vector_factory.h"
#include <climits>

class client_impl {

    using Factory = std::unique_ptr<atlas::collections::vector_factory<int> >;
public:
    explicit client_impl(Factory factory) : factory(std::move(factory)) {}

    auto go()-> void {
        auto data = factory->create_and_fill_vector(INT32_MAX/16);

        for (int i = 0; i < 10; ++i) {
            std::cout << (*data)[i] << std::endl;
        }
    }

private:
    Factory factory;
};
