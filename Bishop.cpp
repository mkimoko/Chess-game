//
// Created by Mathieu on 18/12/2017.
//
#include "Bishop.h"
#include <cstdlib>

Bishop::Bishop(Position position)
{
    m_position = position;
    m_nb_moves = 0;
}

int Bishop::deplacement(Position position){

    if (getPosition().getCol() != position.getCol() || getPosition().getRow() != position.getRow()){

        int col_decal = abs( getPosition().getCol()- position.getCol() );
        int row_decal = abs( getPosition().getRow()- position.getRow() );

        if( col_decal == row_decal ){

            m_position.placement(position.getCol(), position.getRow());
            m_nb_moves++;
            return 1;
        }
    }
    return 0;
}





int Bishop::kill(Piece & piece){

    if( getPosition().getCol() != piece.getPosition().getCol() || getPosition().getRow() != piece.getPosition().getRow() ){

        int col_decal = abs(getPosition().getCol()- piece.getPosition().getCol());
        int row_decal = abs(getPosition().getRow()- piece.getPosition().getRow());

        if( col_decal == row_decal  ){

            getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            return 1;
        }

    }


    return 0;

}

int Bishop::specialMove(Position position){ return 0; }
