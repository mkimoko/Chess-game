//
// Created by Mathieu on 18/12/2017.
//

#ifndef ECHEC_ROOK_H
#define ECHEC_ROOK_H

#include "Piece.h"

class Rook : public Piece{
    public:
        int getCode();
        Rook(Position position);
        Rook(int col, int row);
        int deplacement(Position position, int option);
        int specialMove(Position position);
        int kill(Piece & piece);

    private:
        void print();
};


#endif //ECHEC_ROOK_H
