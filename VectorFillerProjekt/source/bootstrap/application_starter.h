//
// Created by JoachimWagner on 12.07.2023.
//

#pragma once

#include <iostream>

namespace atlas::bootstrap {
    class application_starter {

    public:
        auto run()-> void {
            std::cout << "App wurde gestartet" << std::endl;
        }
    };
}
