//
// Created by JoachimWagner on 11.07.2023.
//

#pragma once

#include <iostream>
#include "writer.h"
namespace atlas::io {
    class consolen_writer:public writer {
    public:
        auto write(std::string message)  const ->void  override {
            std::cout << message << std::endl;
        }

    };
}
