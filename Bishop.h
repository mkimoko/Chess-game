//
// Created by Mathieu on 18/12/2017.
//

#ifndef ECHEC_BISHOP_H
#define ECHEC_BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
    public:
        Bishop(Position position);
        int deplacement(Position position);
        int specialMove(Position position);
        int kill(Piece & piece);

};


#endif //ECHEC_BISHOP_H
