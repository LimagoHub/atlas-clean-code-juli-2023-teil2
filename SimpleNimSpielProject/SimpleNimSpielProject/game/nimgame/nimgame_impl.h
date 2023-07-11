//
// Created by JoachimWagner on 10.07.2023.
//

#pragma once



#include "../abstract_game.h"
#include "../../io/writer.h"
namespace atlas::game {
    class nimgame_impl :public abstract_game<int,int>{


    public:
        ~nimgame_impl() override = default;

        explicit nimgame_impl(atlas::io::writer &writer) : abstract_game(writer) {
            setBoard(23);
        }


    protected:
        [[nodiscard]] auto is_turn_valid() const -> bool { return getMove() >= 1 && getMove() <= 3; }

        auto update_board()-> void { setBoard(getBoard() - getMove()); }

        [[nodiscard]] auto is_gameover() const  -> bool  { // Operation
            return getBoard() < 1 || getPlayers().empty();
        };

    };

}
