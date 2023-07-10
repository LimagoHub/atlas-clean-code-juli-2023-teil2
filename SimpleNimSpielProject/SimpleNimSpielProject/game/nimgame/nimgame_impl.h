//
// Created by JoachimWagner on 10.07.2023.
//

#pragma once

#include <iostream>
#include "../game.h"
namespace atlas::game {
    class nimgame_impl :public game{

    public:
        nimgame_impl():stones{23} {}
        auto play() -> void override {
            while( ! is_gameover() ) {
                play_round();
            }
        }

    private:
         auto play_round()-> void {// Integration
            human_move();
            computer_move();
        }

        auto human_move()-> void {

            if(is_gameover()) return;
            execute_move();
            terminate_move( "Mensch");
        }



        auto execute_move()->void  {
            do {
                request_players_move();
            } while(turn_is_invalid());
        }

        bool turn_is_invalid() {
            if(is_turn_valid()) return false;
            std::cout << "Ungueltiger Zug!" << std::endl;
            return true;

        }

        void request_players_move()  {
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3." << std::endl;
            std::cin >> move;
        }


        auto  computer_move()-> void {

            if(is_gameover()) return;

            const int moves[] = {3,1,1,2};

            move = moves[stones % 4];
            std::cout << "Computer nimmt" << move << " Steine." << std::endl;

            terminate_move("Computer");
        }

        void terminate_move( std::string player) {
            update_board();
            print_gameover_message_if_game_is_over(player);
        }

        void print_gameover_message_if_game_is_over(const std::string &player) {
            if(is_gameover()) {
                std::cout << player << " hat verloren" << std::endl;
            }
        }

        // -------- Sumpf -------------------

        bool is_turn_valid() const { return move >= 1 && move <= 3; }

        auto update_board()-> void { stones -= move; }

        auto is_gameover() -> bool { // Operation
            return stones < 1;
        };
        int stones;
        int move;

    };

}
