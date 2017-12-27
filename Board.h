//
// Created by Mathieu on 24/12/2017.
//

#ifndef ECHEC_BOARD_H
#define ECHEC_BOARD_H


#include "Player.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"

class Board {

    private:
        Player m_p1;
        Player m_p2;

    public:
        Board();
        void printTab();
        Piece * piece(Position position);
        Player & getPlayer1();
        Player & getPlayer2();
        void deplacement(int id,Position start, Position end);
        bool accessibility(Piece * piece, Position p);
    private:
        bool accessibility(Pawn * pawn, Position p);
        bool accessibility(Rook *rook, Position p);
        bool accessibility(Bishop * bishop, Position p);
        bool accessibility(Knight * knight, Position p);
        /*bool accessibility(Queen * queen, Position p);
        bool accessibility(King * king, Position p);*/
};


#endif //ECHEC_BOARD_H
