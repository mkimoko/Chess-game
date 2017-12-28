#include <iostream>

#include "includes/Position.h"
#include "includes/Piece.h"
#include "includes/Pawn.h"
#include "includes/Rook.h"
#include "includes/Bishop.h"
#include "includes/Queen.h"
#include "includes/Knight.h"
#include "includes/King.h"
#include "includes/Player.h"
#include "includes/Board.h"
#include "includes/Game.h"

int main() {

    Game game = Game();
    //game.choice();
    //game.positionChoice();
    game.play();
    return 0;
}