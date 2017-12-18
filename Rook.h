//
// Created by Mathieu on 18/12/2017.
//

#ifndef ECHEC_ROOK_H
#define ECHEC_ROOK_H

#include "Piece.h"

class Rook : public Piece{
    public:
        Rook(Position position);
        int deplacement(Position position);
        int specialMove(Position position);
        int kill(Piece & piece);
};


#endif //ECHEC_ROOK_H
