//
// Created by Mathieu on 18/12/2017.
//

#ifndef ECHEC_QUEEN_H
#define ECHEC_QUEEN_H

#include "Piece.h"
#include "Bishop.h"
#include "Rook.h"


class Queen : public Piece{
    private:
        Bishop m_bishop;
        Rook m_rook;

    public:
        Queen(Position position);
        Bishop getBishop();
        Rook getRook();

        void positionement(Position position);
        int deplacement(Position position);
        int specialMove(Position position);
        int kill(Piece & piece);
};


#endif //ECHEC_QUEEN_H
