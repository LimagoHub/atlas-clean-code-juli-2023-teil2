//
// Created by JoachimWagner on 11.07.2023.
//

#pragma once

#include <vector>
#include <iostream>
#include "game.h"
#include "player/player.h"
#include "../io/writer.h"
namespace atlas::game {
    template<class BOARD, class MOVE>
    class abstract_game: public game{

        using player_pointer = player<BOARD,MOVE>*;
    public:
        explicit abstract_game(io::writer &writer) : writer_(writer) {}

        ~abstract_game() override = default;


        auto play() -> void override {
            while( ! is_gameover() ) {
                play_round();
            }
        }

        virtual auto add_player(player_pointer player)-> void {
            players.emplace_back(player);
        }

        virtual auto remove_player(player_pointer player)-> void {

            // TODO Implement Method
            throw std::invalid_argument("Not implemented yet");
        }
    private:
        auto play_round()-> void {// Integration
            for(const auto & player: players) {
                current_player = player;
                play_single_move();
            }

        }

        auto play_single_move()-> void {

            if(is_gameover()) return;
            execute_move();
            terminate_move( );
        }

        auto execute_move()->void  {
            do {
                move = current_player->do_move(board);
            } while(turn_is_invalid());
        }

        auto terminate_move()-> void {
            update_board();
            print_gameover_message_if_game_is_over();
        }

        [[nodiscard]]  bool turn_is_invalid() const {
            if(is_turn_valid()) return false;
            write("Ungueltiger Zug!");
            return true;

        }

        auto print_gameover_message_if_game_is_over() const -> void {
            if(is_gameover()) {
                write( current_player->get_name() + " hat verloren");
            }
        }

        BOARD board;
        MOVE move;
        std::vector<player_pointer> players;
        player_pointer current_player;
        atlas::io::writer &writer_;

    protected:

        const std::vector<player_pointer> &getPlayers() const {
            return players;
        }

        const player<BOARD, MOVE> *getCurrentPlayer() const {
            return current_player;
        }


        BOARD getBoard() const {
            return board;
        }

        void setBoard(BOARD board) {
            abstract_game::board = board;
        }

        MOVE getMove() const {
            return move;
        }

        void setMove(MOVE move) {
            abstract_game::move = move;
        }

    protected:
        auto write(std::string message) const -> void {
            writer_.write(message);
        }
        virtual auto is_gameover() const -> bool = 0;
        virtual auto is_turn_valid() const -> bool = 0;

        virtual auto update_board()-> void = 0;
    };
}
