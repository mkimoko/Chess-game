//
// Created by Mathieu on 18/12/2017.
//

#include "Queen.h"

Queen::Queen(Position position):m_bishop(position), m_rook(position)
{

    m_position = position;
    m_nb_moves = 0;
}

Bishop Queen::getBishop(){
    return m_bishop;
}

Rook Queen::getRook(){
    return m_rook;
}

void Queen::positionement(Position position) {
    getPosition().placement(position.getCol(), position.getRow());
    getBishop().getPosition().placement(position.getCol(), position.getRow());
    getRook().getPosition().placement(position.getCol(), position.getRow());
}

int Queen::deplacement(Position position){

    std::cout<< getNbMoves()<<std::endl;
   getRook().deplacement(position);
    if (getRook().deplacement(position) == 1){
        positionement(getRook().getPosition());
        m_nb_moves++;
        std::cout<< getNbMoves()<<std::endl;
        return 1;
    }

    std::cout<< getNbMoves()<<std::endl;
    getBishop().deplacement(position);
    if (getBishop().deplacement(position) == 1){
        positionement(getBishop().getPosition());
        m_nb_moves++;
        std::cout<< getNbMoves()<<std::endl;
        return 1;
    }

    return 0;
}

int Queen::specialMove(Position position){
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



int Queen::kill(Piece & piece){

    /*if( getPosition().getCol() != piece.getPosition().getCol() || getPosition().getRow() != piece.getPosition().getRow() ){

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
        std::cout<< "Impossible"<<std::endl;*/

    return 0;

}

