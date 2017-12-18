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

    if (getPosition().getCol() != position.getCol() || getPosition().getRow() != position.getRow()){

        if( position.getCol() == getPosition().getCol() || position.getRow() == getPosition().getRow() ) {

            m_position.placement(position.getCol(), position.getRow());
            m_nb_moves++;
            return 1;
        }
    }



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

   /* if( piece.getPosition().getCol() == getPosition().getCol()+1 ){


        if( piece.getPosition().getRow() == getPosition().getRow()-1){


            getPosition()();
            std::cout << "+++++++++++++++++++++++++" << std::endl;
            getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            getPosition()();
            return 1;
        }

        if( piece.getPosition().getRow() == getPosition().getRow()+1 ){

            getPosition()();
            std::cout << "***********************" << std::endl;
            getPosition().placement(piece.getPosition().getCol(), piece.getPosition().getRow() );
            getPosition()();
            return 1;
        }

    }

    else
        std::cout<< "Impossible"<<std::endl;*/

    return 0;


}