//
// Created by Mathieu on 18/12/2017.
//

#include "Queen.h"

Queen::Queen(Position position):m_bishop(position), m_rook(position)
{

    std::cout << "------------------Constructor -------------- " << std::endl;
    m_position = position;
    m_nb_moves = 0;
    std::cout << "Queen " ; getPosition()();
    std::cout << "Bishop " ; getBishop().getPosition()();
    std::cout << "Rook " ; getRook().getPosition()();

    std::cout << "------------------Constructor FIN-------------- " << std::endl<< std::endl;
}

Bishop & Queen::getBishop(){
    return m_bishop;
}

Rook & Queen::getRook(){
    return m_rook;
}

void Queen::positionement(Position position) {
    getPosition().placement(position.getCol(), position.getRow());
    std::cout << "Queen " ; getPosition()();
    getBishop().getPosition().placement(position.getCol(), position.getRow());
    std::cout << "Bishop " ; getBishop().getPosition()();
    getRook().getPosition().placement(position.getCol(), position.getRow());
    std::cout << "Rook " ; getRook().getPosition()();
}

int Queen::deplacement(Position position){

    std::cout<< getNbMoves()<<std::endl;
    std::cout << "------------------Recapitulatif -------------- " << std::endl<< std::endl;

    if (getRook().deplacement(position) == 1){
        positionement(getRook().getPosition());
        std::cout << "----------------------------------------------- " << std::endl<< std::endl;
        m_nb_moves++;
        std::cout<< getNbMoves()<<std::endl;
        return 1;
    }

    if (getBishop().deplacement(position) == 1){
        positionement(getBishop().getPosition());
        std::cout << "----------------------------------------------- " << std::endl<< std::endl;
        m_nb_moves++;
        std::cout<< getNbMoves()<<std::endl;
        return 1;
    }

    return 0;
}

int Queen::specialMove(Position position){

    return 0;
}


int Queen::kill(Piece & piece){

    std::cout<< getNbMoves()<<std::endl;
    std::cout << "------------------Recapitulatif -------------- " << std::endl<< std::endl;
    //getRook().deplacement(position);
    if (getRook().deplacement(piece.getPosition()) == 1){
        positionement(getRook().getPosition());
        std::cout << "----------------------------------------------- " << std::endl<< std::endl;
        m_nb_moves++;
        std::cout<< getNbMoves()<<std::endl;
        return 1;
    }

    if (getBishop().deplacement(piece.getPosition()) == 1){
        positionement(getBishop().getPosition());
        std::cout << "----------------------------------------------- " << std::endl<< std::endl;
        m_nb_moves++;
        std::cout<< getNbMoves()<<std::endl;
        return 1;
    }

    std::cout << "------------------ Impossible -------------- " << std::endl<< std::endl;
    return 0;

}

