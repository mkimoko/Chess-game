//
// Created by Mathieu on 18/12/2017.
//

#include "Pawn.h"
#include "Out_of_Board.h"


Pawn::Pawn(Position position)
{
    m_position = position;
    m_nb_moves = 0;
}

int Pawn::getCode(){
    return 1;
}

Pawn::Pawn(int col, int row) {
    m_position = Position(col, row);
    m_nb_moves = 0;
}

void Pawn::print() {
    std::cout << "p";
}

int Pawn::deplacement(Position position){

    if( position.getRow() < 1 || position.getRow() > 8 || position.getCol() < 1 || position.getCol() > 8){
        throw Out_of_Board();
    }

    if( position.getCol() == getPosition().getCol() && position.getRow() == getPosition().getRow()+1 ) {
        /*m_position.placement(position.getCol(), getPosition().getRow());
        m_nb_moves++;*/
        return 1;
    }

    return 0;
}



int Pawn::kill(Piece & piece){

    if( piece.getPosition().getRow() < 1 || piece.getPosition().getRow() > 8 || piece.getPosition().getCol() < 1 || piece.getPosition().getCol() > 8){
        throw Out_of_Board();
    }

    if( piece.getPosition().getCol() == getPosition().getCol()+1 ){

        if( piece.getPosition().getRow() == getPosition().getRow()-1){
            getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            m_nb_moves++;
            return 1;
        }
        if( piece.getPosition().getRow() == getPosition().getRow()+1 ){
            getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            m_nb_moves++;
            return 1;
        }
    }
    return 0;
}

int Pawn::specialMove(Position position){

    if( position.getRow() < 1 || position.getRow() > 8 || position.getCol() < 1 || position.getCol() > 8){
        throw Out_of_Board();
    }

    if( getNbMoves() == 0){
        if( position.getCol() == getPosition().getCol() && position.getRow() == getPosition().getRow()+2 ) {

            m_position.placement(position.getCol(), getPosition().getRow());
            m_nb_moves++;

            return 1;
        }

    }
}