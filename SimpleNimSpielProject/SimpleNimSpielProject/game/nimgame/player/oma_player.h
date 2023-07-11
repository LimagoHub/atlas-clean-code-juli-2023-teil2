//
// Created by JoachimWagner on 11.07.2023.
//

#pragma once

#pragma once

#include <iostream>
#include "abstract_nimgame_player.h"
namespace atlas::game {

    class oma_player: public abstract_nimgame_player{

    public:
        explicit oma_player(const std::string &name) : abstract_nimgame_player(name) {}

        ~oma_player() override = default;

        auto do_move(const int &stones) const -> int override {
            int move = rand() % 5;
            std::cout << "Oma nimmt " << move << " Steine." << std::endl;

            return move;
        }
    };
}
