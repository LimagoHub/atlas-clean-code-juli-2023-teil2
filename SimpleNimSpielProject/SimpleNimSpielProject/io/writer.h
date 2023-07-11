//
// Created by JoachimWagner on 11.07.2023.
//

#pragma once

#include <string>

namespace atlas::io {
    class writer {
    public:
        virtual auto write(std::string message) const ->void   = 0;

    };
}
