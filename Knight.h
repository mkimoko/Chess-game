//
// Created by Mathieu on 23/12/2017.
//

#ifndef ECHEC_KNIGHT_H
#define ECHEC_KNIGHT_H


#include "Piece.h"

class Knight : public Piece {
    public:
        Knight(Position position);
        int deplacement(Position position);
        int specialMove(Position position);
        int kill(Piece & piece);

};


#endif //ECHEC_KNIGHT_H
