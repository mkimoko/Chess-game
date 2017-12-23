#include <iostream>
#include "Position.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"

int main() {
    Position position;
    Position p;

    position = Position();
    p = Position();
    position.placement(15,15);
    p.placement(17,14);



    /*Knight mangeur = Knight(position);
    Pawn mangee = Pawn(p);
    mangeur.kill(mangee);*/

    King *king = new King(position);
    king->deplacement(p);
    /*reine->getBishop().getPosition()();
    reine->getRook().getPosition()();*/
    /*fou->deplacement(p);
    fou->getPosition()();*/




    return 0;
}