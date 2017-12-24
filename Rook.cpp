//
// Created by Mathieu on 18/12/2017.
//

#include "Rook.h"

Rook::Rook(Position position)
{
    m_position = position;
    m_nb_moves = 0;
}

Rook::Rook(int col, int row) {
    m_position = Position(col, row);
    m_nb_moves = 0;
}

void Rook::print() {
    std::cout << " r " << std::endl;
}

int Rook::deplacement(Position position){

    if (getPosition().getCol() != position.getCol() || getPosition().getRow() != position.getRow()){
        if( position.getCol() == getPosition().getCol() || position.getRow() == getPosition().getRow() ) {

            m_position.placement(position.getCol(), position.getRow());
            m_nb_moves++;
            return 1;
        }
    }
    return 0;

}



int Rook::kill(Piece & piece){


    if( getPosition().getCol() != piece.getPosition().getCol() || getPosition().getRow() != piece.getPosition().getRow() ){

        if( piece.getPosition().getCol() == getPosition().getCol() ){
            getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            return 1;
        }

        if( piece.getPosition().getRow() == getPosition().getRow() ){
            getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            return 1;
        }

    }

    return 0;


}

int Rook::specialMove(Position position){ return 0; }