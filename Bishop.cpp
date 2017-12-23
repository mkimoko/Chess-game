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

    std::cout << "------------------Before Deplacement Bishop-------------- " << std::endl;
    getPosition()();
    std::cout << "----------------------------------------------------" << std::endl;

    if (getPosition().getCol() != position.getCol() || getPosition().getRow() != position.getRow()){

        int col_decal = abs( getPosition().getCol()- position.getCol() );
        int row_decal = abs( getPosition().getRow()- position.getRow() );

        if( col_decal == row_decal ){

            m_position.placement(position.getCol(), position.getRow());
            std::cout << "--------------During Deplacement Bishop:------------- " << std::endl;
            getPosition()();
            std::cout << "----------------------------------------------------" << std::endl;
            m_nb_moves++;

            std::cout << "------------------After Deplacement Bishop -------------- " << std::endl;
            getPosition()();
            std::cout << "----------------------------------------------------" << std::endl<< std::endl;
            return 1;
        }
    }
    return 0;
}

int Bishop::specialMove(Position position){
    /* if( getNbMoves() == 0){
         if( position.getCol() == getPosition().getCol()+2 && position.getRow() == getPosition().getRow() ) {
             m_position.placement(position.getCol(), getPosition().getRow());
             m_nb_moves++;

             m_position();
             return 1;
         }
     }*/
    return 0;
}



int Bishop::kill(Piece & piece){

    if( getPosition().getCol() != piece.getPosition().getCol() || getPosition().getRow() != piece.getPosition().getRow() ){

        int col_decal = abs(getPosition().getCol()- piece.getPosition().getCol());
        int row_decal = abs(getPosition().getRow()- piece.getPosition().getRow());

        if( col_decal == row_decal  ){

            getPosition()();
            std::cout << "+++++++++++++++++++++++++" << std::endl;
            getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            getPosition()();
            return 1;
        }

    }

    else
        std::cout<< "Impossible"<<std::endl;

    return 0;

}
