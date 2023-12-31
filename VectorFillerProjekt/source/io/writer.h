//
// Created by JoachimWagner on 12.07.2023.
//

#pragma once

#include <string>

namespace atlas::io {

    class writer {

    public:
        virtual ~writer() = default;

        virtual auto write(std::string message) const -> void  = 0;

    };

}
