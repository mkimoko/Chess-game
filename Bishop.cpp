//
// Created by Mathieu on 18/12/2017.
//
#include "includes\Bishop.h"
#include "includes\exception\Out_of_Board.h"
#include <cstdlib>

Bishop::Bishop(Position position)
{
    m_position = position;
    m_nb_moves = 0;
}

Bishop::Bishop(int col, int row) {
    m_position = Position(col, row);
    m_nb_moves = 0;
}

int Bishop::getCode() {
    return 3;
}

void Bishop::print(){
    std::cout << "b";
}

int Bishop::deplacement(Position position, int option){

    if( position.getRow() < 1 || position.getRow() > 8 || position.getCol() < 1 || position.getCol() > 8){
        throw Out_of_Board();
    }

    if (getPosition().getCol() != position.getCol() || getPosition().getRow() != position.getRow()){

        int col_decal = abs( getPosition().getCol()- position.getCol() );
        int row_decal = abs( getPosition().getRow()- position.getRow() );

        if( col_decal == row_decal ){

            /*m_position.placement(position.getCol(), position.getRow());
            m_nb_moves++;*/
            return 1;
        }
    }
    return 0;
}





int Bishop::kill(Piece & piece){

    if( piece.getPosition().getRow() < 1 || piece.getPosition().getRow() > 8 || piece.getPosition().getCol() < 1 || piece.getPosition().getCol() > 8){
        throw Out_of_Board();
    }

    if( getPosition().getCol() != piece.getPosition().getCol() || getPosition().getRow() != piece.getPosition().getRow() ){

        int col_decal = abs(getPosition().getCol()- piece.getPosition().getCol());
        int row_decal = abs(getPosition().getRow()- piece.getPosition().getRow());

        if( col_decal == row_decal  ){

            //getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            return 1;
        }

    }


    return 0;

}

int Bishop::specialMove(Position position){ return 0; }
