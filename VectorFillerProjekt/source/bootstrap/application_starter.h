//
// Created by JoachimWagner on 12.07.2023.
//

#pragma once

#include <iostream>
#include "../generators/random/mersenne_twister_number_generator.h"
#include "../collections/impl/sequential/vector_factory_sequential_impl.h"
#include "../clients/client_impl.h"
#include "../time/decorator.h"

namespace atlas::bootstrap {
    class application_starter {

        using GeneratorPointer = std::unique_ptr<atlas::generators::generator<int>>;
        using VectorFactoryPointer = std::unique_ptr<atlas::collections::vector_factory<int>>;

        static auto create()  -> int {

            GeneratorPointer generator_ = create_generator();
            VectorFactoryPointer factory_ = create_vector_factory(std::move(generator_));

            client_impl client{std::move(factory_)};
            client.go();
            return 0;
        }

        static VectorFactoryPointer create_vector_factory(GeneratorPointer generator_) {
            VectorFactoryPointer factory_ = std::make_unique<collections::vector_factory_sequential_impl<int>>(std::move(generator_));
            return factory_;
        }

        static GeneratorPointer create_generator() {
            GeneratorPointer generator_ = std::make_unique<generators::mersenne_twister_number_generator>();
            return generator_;
        }

    public:
        auto run() const-> void {
            create();
            std::cout << "App wurde gestartet" << std::endl;
        }
    };
}
