//
// Created by Mathieu on 23/12/2017.
//

#ifndef ECHEC_KING_H
#define ECHEC_KING_H


#include "Piece.h"

class King : public Piece{

    public:
        King(Position position);
        int deplacement(Position position);
        int specialMove(Position position);
        int kill(Piece & piece);
};


#endif //ECHEC_KING_H
