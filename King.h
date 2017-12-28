//
// Created by Mathieu on 23/12/2017.
//

#ifndef ECHEC_KING_H
#define ECHEC_KING_H


#include "Piece.h"

class King : public Piece{

    public:
        King(Position position);
        King(int col, int row);
        int getCode();
        int deplacement(Position position,int option);
        int specialMove(Position position);
        int kill(Piece & piece);

    private:
        void print();
};


#endif //ECHEC_KING_H
