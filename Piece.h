//
// Created by Mathieu on 18/12/2017.
//
#include "Position.h"

#ifndef ECHEC_PIECE_H
#define ECHEC_PIECE_H


class Piece {

    protected:

        Position  m_position;
        int m_nb_moves; // number of player's move with this piece

    public:
        //~Piece();
        Position & getPosition();
        int getNbMoves();
        virtual int deplacement(Position position) = 0;
        virtual int specialMove(Position position) = 0;
        virtual int kill(Piece & piece) = 0;

};


#endif //ECHEC_PIECE_H