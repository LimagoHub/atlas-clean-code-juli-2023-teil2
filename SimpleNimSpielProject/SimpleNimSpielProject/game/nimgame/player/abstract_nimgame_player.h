//
// Created by JoachimWagner on 11.07.2023.
//

#pragma once
#include "../../player/abstract_player.h"
namespace atlas::game {
    class abstract_nimgame_player: public abstract_player<int,int>{
    public:


        explicit abstract_nimgame_player(const std::string &name) : abstract_player(name) {}


    };
}
