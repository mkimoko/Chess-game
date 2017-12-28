//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
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
    void kill(int id, Position start, Position end);
    bool accessibility(Piece * piece, Position p, int option);
    bool threatned(int id);
    bool win(int id);
private:
    bool accessibility(Pawn * pawn, Position p, int option);
    bool accessibility(Rook *rook, Position p, int option);
    bool accessibility(Bishop * bishop, Position p, int option);
    bool accessibility(Knight * knight, Position p, int option);
    bool accessibility(Queen * queen, Position p, int option);
    bool accessibility(King * king, Position p, int option);
};
#endif //CHESS_BOARD_H
