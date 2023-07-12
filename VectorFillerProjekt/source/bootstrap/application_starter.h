//
// Created by JoachimWagner on 12.07.2023.
//

#pragma once

#include <iostream>
#include "../generators/random/mersenne_twister_number_generator.h"
#include "../collections/impl/sequential/vector_factory_sequential_impl.h"
#include "../clients/client_impl.h"

using namespace atlas::collections;
namespace atlas::bootstrap {
    class application_starter {

        using GeneratorPointer = std::unique_ptr<atlas::generators::generator<int>>;
        using VectorFactoryPointer = std::unique_ptr<vector_factory<int>>;

        auto create()-> void {
            GeneratorPointer generator_ = std::make_unique<atlas::generators::mersenne_twister_number_generator>();
            VectorFactoryPointer factory_ = std::make_unique<vector_factory_sequential_impl<int>>(std::move(generator_));
            client_impl client{std::move(factory_)};
            client.go();
        }

    public:
        auto run()-> void {

            create();
            std::cout << "App wurde gestartet" << std::endl;
        }
    };
}
