//
// Created by Mathieu on 18/12/2017.
//

#include "Rook.h"

Rook::Rook(Position position)
{
    m_position = position;
    m_nb_moves = 0;
}

int Rook::deplacement(Position position){
    std::cout << "------------------Before Deplacement Rook -------------- " << std::endl;
    getPosition()();
    std::cout << "----------------------------------------------------" << std::endl;

    if (getPosition().getCol() != position.getCol() || getPosition().getRow() != position.getRow()){
        if( position.getCol() == getPosition().getCol() || position.getRow() == getPosition().getRow() ) {

            m_position.placement(position.getCol(), position.getRow());
            m_nb_moves++;
            std::cout << "--------------During Deplacement Rook:------------- " << std::endl;
            getPosition()();
            std::cout << "----------------------------------------------------" << std::endl;
            return 1;
        }
    }
    std::cout << "------------------After Deplacement Rook-------------- " << std::endl;
    getPosition()();
    std::cout << "----------------------------------------------------" << std::endl<< std::endl;
    return 0;

}

int Rook::specialMove(Position position){

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

int Rook::kill(Piece & piece){


    if( getPosition().getCol() != piece.getPosition().getCol() || getPosition().getRow() != piece.getPosition().getRow() ){

        if( piece.getPosition().getCol() == getPosition().getCol() ){


            getPosition()();
            std::cout << "+++++++++++++++++++++++++" << std::endl;
            getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            getPosition()();
            return 1;
        }

        if( piece.getPosition().getRow() == getPosition().getRow() ){

            getPosition()();
            std::cout << "***********************" << std::endl;
            getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            getPosition()();
            return 1;
        }

    }

    else
        std::cout<< "Impossible"<<std::endl;

    return 0;


}