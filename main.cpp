#include <iostream>
#include <map>
#include "Position.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"
#include "Player.h"
#include "Board.h"

int main() {

   /* Pawn* pawn = new Pawn(1,2);
    Rook* rook = new Rook(3,4);
    Bishop* bishop = new Bishop(5,6);
    Knight* knight = new Knight(7,8);
    Queen* queen = new Queen(9,10);
    King* king = new King(11,12);

    pawn->deplacement(Position(2,2));
    pawn->deplacement(Position(3,2));
    pawn->deplacement(Position(4,2));
    pawn->deplacement(Position(5,2));


    rook->deplacement(Position(2,4));
    rook->deplacement(Position(1,4));
    rook->deplacement(Position(9,4));

    bishop->deplacement(Position(6,7));
    bishop->deplacement(Position(4,5));

    std::map<Piece *,bool> army = { {pawn,true}, {rook,true}, {bishop, false},{knight,true},{queen, false},{king,true} };*/

    //Player player(army);

    //player.classement();

    /*std::vector<Piece *>::iterator it;
    int i = 0;
    for (it = player.dead().begin(); it != player.dead().end(); it++){
        player.dead().at(i)->operator()();
        i++;
    }*/

    Board board ;
    board.printTab();






//Créer template comportement fonction
    //template piece se comporte différemment en fonction type
    //retourne 1 si on 0 sinon
//Paire piece mangé ou pas bool
//Template Board, int pour historique
//classment des piece plus joué stl

    return 0;
}