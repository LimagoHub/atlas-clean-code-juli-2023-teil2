//
// Created by JoachimWagner on 12.07.2023.
//

#pragma once

#include <iostream>
#include "../generators/random/mersenne_twister_number_generator.h"
#include "../generators/random/mersenne_twister_number_generator_factory.h"
#include "../collections/impl/sequential/vector_factory_sequential_impl.h"
#include "../collections/impl/decoraters/vector_factory_security_decorator.h"
#include "../collections/impl/decoraters/vector_factory_benchmark_decorator.h"
#include "../collections/impl/decoraters/vector_factory_logger_decorator.h"
#include "../collections/impl/parallel/vector_factory_parallel_impl.h"
#include "../collections/impl/parallel/vector_factory_parallel_auto_impl.h"
#include "../clients/client_impl.h"
#include "../time/decorator.h"

namespace atlas::bootstrap {
    class application_starter {

        using GeneratorPointer = std::unique_ptr<atlas::generators::generator<int>>;
        using GeneratorFactoryPointer = std::unique_ptr<atlas::generators::generator_factory<int>>;
        using VectorFactoryPointer = std::unique_ptr<atlas::collections::vector_factory<int>>;

        static auto create(size_t threadCount = 1)  -> int {

            std::cout << "Durchlauf mit " << threadCount << " Threads ";
            GeneratorFactoryPointer generatorFactory_ = create_generator_factory();
            VectorFactoryPointer factory_ = create_vector_factory(std::move(generatorFactory_),threadCount);

            client_impl client{std::move(factory_)};
            client.go();
            return 0;
        }

        static VectorFactoryPointer create_vector_factory(GeneratorFactoryPointer generator_factory_, size_t threadCount) {
            VectorFactoryPointer factory_ ;
            factory_ = std::make_unique<collections::vector_factory_parallel_impl<int>>(std::move(generator_factory_), threadCount);
            factory_ = std::make_unique<atlas::collections::vector_factory_logger_decorator<int>>(std::move(factory_));
            factory_ = std::make_unique<atlas::collections::vector_factory_security_decorator<int>>(std::move(factory_));
            factory_ = std::make_unique<atlas::collections::vector_factory_benchmark_decorator<int>>(std::move(factory_));
            return factory_;
        }

        static GeneratorPointer create_generator() {
            GeneratorPointer generator_ = std::make_unique<generators::mersenne_twister_number_generator>();
            return generator_;
        }

        static GeneratorFactoryPointer create_generator_factory() {
            GeneratorFactoryPointer generator_factory_ = std::make_unique<generators::mersenne_twister_number_generator_factory>();
            return generator_factory_;
        }

    public:
        auto run() const-> void {
            auto availableProcessors = std::thread::hardware_concurrency();
            for (size_t threadCount = 1; threadCount <= availableProcessors + 1; ++threadCount) {
                create(threadCount);
                std::cout << "App wurde gestartet" << std::endl;
            }
        }
    };
}
