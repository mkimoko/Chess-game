#include <iostream>
#include "Position.h"
#include "Piece.h"
#include "Pawn.h"

int main() {
    Position position;
    Position p;

    position = Position();
    p = Position();
    p.placement(14,4);
    position.placement(13,3);



    Pawn mangeur = Pawn(position);
    Pawn mangee = Pawn(p);

    mangeur.kill(mangee);

    /*pion->deplacement(p);
    p.placement(16,3);
    pion->specialMove(p);*/


    return 0;
}