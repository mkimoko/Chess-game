//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_KNIGNT_H
#define CHESS_KNIGNT_H

#include "Piece.h"

class Knight : public Piece {
public:
    int getCode();
    Knight(Position position);
    Knight(int col, int row);
    int deplacement(Position position, int option);
    int specialMove(Position position);
    int kill(Piece & piece);

private:
    void print();

};

#endif //CHESS_KNIGNT_H
