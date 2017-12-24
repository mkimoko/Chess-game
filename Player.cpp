//
// Created by Mathieu on 23/12/2017.
//

#include "Player.h"
#include <algorithm>

Player::Player(int id) {
    m_id = id;
    m_army = std::map<Piece *, bool>();
}

Player::Player(std::map< Piece *, bool > army){
    m_army = army;
}

/*bool Player::operator<(Piece * p1, Piece * p2){

    if (p1->getNbMoves() < p2->getNbMoves())
        return true;

    return false;
}*/


std::map<Piece *, bool> & Player::getArmy(){
    return m_army;
}

Piece * Player::piece(Position position){
std::map<Piece*,bool>::iterator it;

    for(it = m_army.begin(); it!= m_army.end(); it++)
    {
        if (it->second == true){
            if(it->first->getPosition() == position){
                return (it->first);
            }
        }

    }
}


std::vector< Piece * > Player::alive(){
    std::map<Piece *,bool>::iterator it;
    std::vector<Piece *> army;

    for(it = m_army.begin(); it!= m_army.end(); it++)
    {
        if (it->second == true){
            army.push_back(it->first);
        }
    }

    return army;
}

std::vector< Piece * > Player::dead(){
    std::map<Piece *,bool>::iterator it;
    std::vector<Piece *> army;

    for(it = m_army.begin(); it!= m_army.end(); it++)
    {
        if (it->second == false){
            army.push_back(it->first);
        }
    }
    return army;
}

std::vector<Piece *> Player::classement()const{
    std::vector<Piece *> result;
    std::map<Piece *, bool>::const_iterator it;

    for(it = m_army.begin(); it!= m_army.end(); it++)
    {
            result.push_back(it->first);
    }

    std::sort(result.begin(), result.end());

    for (int i = 0; i < result.size() ; i++) {
        result.at(i)->operator()();
    }
    return result;
}