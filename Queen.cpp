//
// Created by Mathieu on 18/12/2017.
//

#include "Queen.h"

Queen::Queen(Position position):m_bishop(position), m_rook(position)
{
    m_position = position;
    m_nb_moves = 0;
}

Bishop & Queen::getBishop(){
    return m_bishop;
}

Rook & Queen::getRook(){
    return m_rook;
}

void Queen::print() {
    std::cout << " q " << std::endl;
}

void Queen::positionement(Position position) {
    getPosition().placement(position.getCol(), position.getRow());
    getBishop().getPosition().placement(position.getCol(), position.getRow());
    getRook().getPosition().placement(position.getCol(), position.getRow());
}

int Queen::deplacement(Position position){

    std::cout<< getNbMoves()<<std::endl;

    if (getRook().deplacement(position) == 1){
        positionement(getRook().getPosition());
        m_nb_moves++;
        return 1;
    }

    if (getBishop().deplacement(position) == 1){
        positionement(getBishop().getPosition());
        m_nb_moves++;
        return 1;
    }

    return 0;
}



int Queen::kill(Piece & piece){

    if (getRook().deplacement(piece.getPosition()) == 1){
        positionement(getRook().getPosition());
        m_nb_moves++;
        return 1;
    }

    if (getBishop().deplacement(piece.getPosition()) == 1){
        positionement(getBishop().getPosition());
        m_nb_moves++;
        return 1;
    }
    return 0;

}

int Queen::specialMove(Position position){return 0; }

