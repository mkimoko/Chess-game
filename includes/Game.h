//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H


#include "Board.h"

class Game{
    private:
        int m_tour ;
        Board m_board;
    public:
        Game();
        void print();//print the board
        int choice();//return an game option
        bool action(int id);//do one play
        Position positionChoice();//choose a position in the board
        void play();

};
#endif //CHESS_GAME_H
