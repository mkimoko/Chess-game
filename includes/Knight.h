//
// Created by Mathieu on 23/12/2017.
//

#ifndef ECHEC_KNIGHT_H
#define ECHEC_KNIGHT_H


#include "Piece.h"

class Knight : public Piece {
    public:
        int getCode();
        Knight(Position position);
        Knight(int col, int row);
        int deplacement(Position position, int option);
        int specialMove(Position position);
        int kill(Piece & piece);

    private:
        void print();

};


#endif //ECHEC_KNIGHT_H
