//
// Created by Mathieu on 18/12/2017.
//

#include "Queen.h"
#include "Out_of_Board.h"

Queen::Queen(Position position):m_bishop(position), m_rook(position)
{
    m_position = position;
    m_nb_moves = 0;
}

Queen::Queen(int col, int row) :m_bishop(col, row), m_rook(col, row){
    m_position = Position(col, row);
    m_nb_moves = 0;
}

int Queen::getCode(){
    return 5;
}
Bishop & Queen::getBishop(){
    return m_bishop;
}

Rook & Queen::getRook(){
    return m_rook;
}

void Queen::print() {
    std::cout << "q";
}

void Queen::positionement(Position position) {
    getPosition().placement(position.getCol(), position.getRow());
    getBishop().getPosition().placement(position.getCol(), position.getRow());
    getRook().getPosition().placement(position.getCol(), position.getRow());
}

int Queen::deplacement(Position position, int option){

    if( position.getRow() < 1 || position.getRow() > 8 || position.getCol() < 1 || position.getCol() > 8){
        throw Out_of_Board();
    }
    if (getRook().deplacement(position, option) == 1){
        /*positionement(getRook().getPosition());
        m_nb_moves++;*/
        return 1;
    }

    if (getBishop().deplacement(position, option) == 1){
        /*positionement(getBishop().getPosition());
        m_nb_moves++;*/
        return 1;
    }

    return 0;
}



int Queen::kill(Piece & piece){

    if( piece.getPosition().getRow() < 1 || piece.getPosition().getRow() > 8 || piece.getPosition().getCol() < 1 || piece.getPosition().getCol() > 8){
        throw Out_of_Board();
    }

    if (getRook().deplacement(piece.getPosition(), 0) == 1){
        /*positionement(getRook().getPosition());
        m_nb_moves++;*/
        return 1;
    }

    if (getBishop().deplacement(piece.getPosition(), 0) == 1){
        /*positionement(getBishop().getPosition());
        m_nb_moves++;*/
        return 1;
    }
    return 0;

}

int Queen::specialMove(Position position){return 0; }

