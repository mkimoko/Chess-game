#include <iostream>
#include "Position.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"

int main() {
    Position position;
    Position p;

    position = Position();
    p = Position();
    p.placement(14,18);
    position.placement(17,15);



   /* Bishop mangeur = Bishop(position);
    Pawn mangee = Pawn(p);
    mangeur.kill(mangee);*/

    Queen *reine = new Queen(position);
    reine->deplacement(p);
    /*reine->getBishop().getPosition()();
    reine->getRook().getPosition()();*/
    /*fou->deplacement(p);
    fou->getPosition()();*/




    return 0;
}