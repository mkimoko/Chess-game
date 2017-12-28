//
// Created by Mathieu on 23/12/2017.
//

#include "Player.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "No_Piece.h"
#include "Obstruction.h"
#include <algorithm>
#include <utility>

Player::Player(int id) {
    m_id = id;
    m_army = std::map<Piece *, bool>();

    if (id == 1){
        for (int i = 1; i <= 8  ; i++) {
            m_army.insert(std::pair<Piece*, bool> (new Pawn(i,2), true));
            if (i == 1 || i == 8)
                m_army.insert(std::pair<Piece *, bool>(new Rook(i,1), true));

            if (i == 2 || i == 7)
                m_army.insert(std::pair<Piece *, bool>(new Knight(i,1), true));

            if (i == 3 || i == 6)
                m_army.insert(std::pair<Piece *, bool>(new Bishop(i,1), true));

            if (i == 4)
                m_army.insert(std::pair<Piece *, bool>(new Queen(i,1), true));

            if (i == 5)
                m_army.insert(std::pair<Piece *, bool>(new King(i,1), true));
        }
    }

    if (id == 2){
        for (int i = 1; i <= 8  ; i++) {
            m_army.insert(std::pair<Piece*, bool> (new Pawn(i,7), true));
            if (i == 1 || i == 8)
                m_army.insert(std::pair<Piece *, bool>(new Rook(i,8), true));

            if (i == 2 || i == 7)
                m_army.insert(std::pair<Piece *, bool>(new Knight(i,8), true));

            if (i == 3 || i == 6)
                m_army.insert(std::pair<Piece *, bool>(new Bishop(i,8), true));

            if (i == 4)
                m_army.insert(std::pair<Piece *, bool>(new Queen(i,8), true));

            if (i == 5)
                m_army.insert(std::pair<Piece *, bool>(new King(i,8), true));
        }
    }

}

int Player::getId(){
    return m_id;
}


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

    throw No_Piece();
}

Piece *Player::getKing(){
    std::map<Piece*,bool>::iterator it;

    for(it = m_army.begin(); it!= m_army.end(); it++)
    {
        if (it->second == true){
            if(it->first->getCode() == 6){
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


