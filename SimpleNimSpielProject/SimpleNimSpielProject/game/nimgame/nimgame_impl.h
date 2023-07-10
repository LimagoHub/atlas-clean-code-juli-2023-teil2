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
         auto play_round()-> void {
            human_move();
            computer_move();
        }

        auto human_move()-> void {

            int move;
            while(true) {
                std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3." << std::endl;
                std::cin >> move;
                if( move >= 1 && move <= 3) break;
                std::cout << "Ungueltiger Zug!" << std::endl;
            }
            stones -= move;

        }

        auto  computer_move()-> void {
            const int moves[] = {3,1,1,2};
            int move;

            if(stones < 1) {
                 std::cout << "Du Loser" << std::endl;
                 return;
            }
            if(stones == 1) {
                std::cout << "Du hast nur Glueck gehabt!" << std::endl;
                return;
            }

            move = moves[stones % 4];
            std::cout << "Computer nimmt" << move << " Steine." << std::endl;

            stones -= move;
        }

        auto is_gameover() -> bool {
            return stones < 1;
        };
        int stones;


    };

}
