//
// Created by Mathieu on 28/12/2017.
//

#include "../includes/Rook.h"
#include "../includes/exception/Out_of_Board.h"

Rook::Rook(Position position)
{
    m_position = position;
    m_nb_moves = 0;
}

int Rook::getCode() {
    return 2;
}
Rook::Rook(int col, int row) {
    m_position = Position(col, row);
    m_nb_moves = 0;
}

void Rook::print() {
    std::cout << "r";
}

int Rook::deplacement(Position position, int option){

    if( position.getRow() < 1 || position.getRow() > 8 || position.getCol() < 1 || position.getCol() > 8){
        throw Out_of_Board();
    }


    if( getPosition().getCol() != position.getCol() || getPosition().getRow() != position.getRow() ){

        if( position.getCol() == getPosition().getCol() ){
            return 1;
        }

        if( position.getRow() == getPosition().getRow() ){
            return 1;
        }

    }

    return 0;

}



int Rook::kill(Piece * piece, int option){

    if( piece->getPosition().getRow() < 1 || piece->getPosition().getRow() > 8 || piece->getPosition().getCol() < 1 || piece->getPosition().getCol() > 8){
        throw Out_of_Board();
    }


    if( getPosition().getCol() != piece->getPosition().getCol() || getPosition().getRow() != piece->getPosition().getRow() ){

        if( piece->getPosition().getCol() == getPosition().getCol() ){
            return 1;
        }

        if( piece->getPosition().getRow() == getPosition().getRow() ){
            return 1;
        }

    }

    return 0;


}

int Rook::specialMove(Position position){ return 0; }