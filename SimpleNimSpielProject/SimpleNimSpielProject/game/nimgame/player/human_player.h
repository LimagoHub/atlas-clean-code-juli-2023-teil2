//
// Created by JoachimWagner on 11.07.2023.
//

#pragma once

#include <iostream>
#include "abstract_nimgame_player.h"
namespace atlas::game {

    class human_player: public abstract_nimgame_player{

    public:
        explicit human_player(const std::string &name) : abstract_nimgame_player(name) {}

        ~human_player() override = default;

        auto do_move(const int &stones) const -> int override {
            int move;
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3." << std::endl;
            std::cin >> move;
            return move;
        }
    };
}
