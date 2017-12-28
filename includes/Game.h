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
        int getTour();
        void print();
        int choice();
        bool action(int id);
        Position positionChoice();
        void play();

};
#endif //CHESS_GAME_H
