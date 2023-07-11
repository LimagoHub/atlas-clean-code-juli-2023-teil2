//
// Created by JoachimWagner on 11.07.2023.
//

#pragma once
#include "player.h"
namespace atlas::game {
    template<class BOARD, class MOVE>
    class abstract_player: public player<BOARD,MOVE>{
    public:
        auto get_name() const -> std::string override {
            return name;
        }

        explicit abstract_player(const std::string &name) : name(name) {}

    private:
        std::string name;
    };
}
