//
// Created by Mathieu on 18/12/2017.
//

#include "Piece.h"

Position & Piece::getPosition() {
    return m_position;
}


int Piece::getNbMoves(){
    return m_nb_moves;
}

void Piece::operator()(){
    print();
}

bool Piece::operator<(Piece * piece) {

    if (getNbMoves() < piece->getNbMoves())
        return true;

    return false;
}

