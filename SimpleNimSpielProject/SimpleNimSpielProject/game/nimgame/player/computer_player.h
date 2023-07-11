//
// Created by JoachimWagner on 11.07.2023.
//
#pragma once

#include <iostream>
#include "abstract_nimgame_player.h"
namespace atlas::game {

    class computer_player: public abstract_nimgame_player{

        inline static  const int moves[] = {3,1,1,2};
    public:
        explicit computer_player(const std::string &name) : abstract_nimgame_player(name) {}

        ~computer_player() override = default;

        auto do_move(const int &stones) const -> int override {
            int move = moves[stones % 4];
            std::cout << "Computer nimmt" << move << " Steine." << std::endl;
            return move;
        }
    };
}
