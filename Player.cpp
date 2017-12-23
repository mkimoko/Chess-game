//
// Created by Mathieu on 23/12/2017.
//

#include "Player.h"

Player::Player(int id) {
    m_id = id;
    m_army = std::vector<Piece>();
}

std::vector<Piece> & Player::getArmy(){
    return m_army;
}

Piece & Player::piece(Position position){
   std::vector<Piece>::iterator it;

    for(it = m_army.begin(); it!=m_army.end(); it++)
    {
        if(it->getPosition() == position){
            return *it;
        }
    }

    return (Piece &) nullptr;

}
