//
// Created by Mathieu on 18/12/2017.
//

#include "Piece.h"

Position & Piece::getPosition(){
    return m_position;
}


int Piece::getNbMoves(){
    return m_nb_moves;
}

/* Piece::~Piece(){
    std::cout << "Piece détruite" << std::endl;
}
Position specialMove(Piece & piece, Position position){}*/


/****************************************************************/


/*void Piece::operator()(Position position){}

void Piece::operator[](Position position){}

void Piece::operator[](Piece & piece){}

void Piece::operator()(){

}*/
