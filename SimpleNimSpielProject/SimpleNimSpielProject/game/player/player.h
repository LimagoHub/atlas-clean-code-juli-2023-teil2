//
// Created by JoachimWagner on 11.07.2023.
//

#pragma once

#include <string>

namespace atlas::game {
    template<class BOARD, class MOVE>
    class player {
    public:
        virtual ~ player() = default;
        virtual auto get_name() const -> std::string = 0;
        virtual auto do_move(const BOARD & board) const -> MOVE = 0;
    };
}
