#include <iostream>
#include "Position.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"

int main() {
    Position position;
    Position p;

    position = Position();
    p = Position();
    p.placement(14,18);
    position.placement(17,16);



    Bishop mangeur = Bishop(position);
    Pawn mangee = Pawn(p);
    mangeur.kill(mangee);

    /*Bishop *fou = new Bishop(position);
    fou->getPosition()();
    fou->deplacement(p);
    fou->getPosition()();*/




    return 0;
}