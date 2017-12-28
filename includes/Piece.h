//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "Position.h"

class Piece {

protected:
    Position  m_position;
    int m_nb_moves; // number of player's move with this piece
    virtual void print() = 0;

public:
    virtual int getCode() =0;
    Position & getPosition();
    int getNbMoves();
    void upNbMoves();//number of moves of a piece
    virtual int deplacement(Position position, int option) = 0;
    virtual int specialMove(Position position) = 0;
    virtual int kill(Piece * piece, int option) = 0;
    //Print the piece
    void operator()();
    bool operator<(Piece * piece);


};

#endif //CHESS_PIECE_H
