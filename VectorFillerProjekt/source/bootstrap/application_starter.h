//
// Created by JoachimWagner on 12.07.2023.
//

#pragma once

#include <iostream>

namespace atlas::bootstrap {
    class application_starter {

    public:
        auto run()-> void {

            // Generator
            // vector_factory (injected Generator)
            // client (inject vector_factory)
            // client.go();
            std::cout << "App wurde gestartet" << std::endl;
        }
    };
}
