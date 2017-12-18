#include <iostream>
#include "Position.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"

int main() {
    Position position;
    Position p;

    position = Position();
    p = Position();
    p.placement(14,10);
    position.placement(14,10);



    /*Pawn mangeur = Pawn(position);
    Pawn mangee = Pawn(p);
    mangeur.kill(mangee);*/

    Rook *tour = new Rook(position);
    tour->getPosition()();
    std::cout << "**********************************" << std::endl;
    tour->deplacement(p);
    tour->getPosition()();
    /*p.placement(16,3);
    pion->specialMove(p);*/


    return 0;
}