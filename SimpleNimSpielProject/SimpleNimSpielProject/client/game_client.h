#pragma once
#include "../game/game.h"
namespace atlas::client {


    class game_client {
        atlas::game::game & game;

    public:
        explicit game_client(game::game &game) : game(game) {}

        auto go() ->void {
            game.play();
        }

    };

}
