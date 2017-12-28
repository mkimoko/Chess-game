//
// Created by Mathieu on 23/12/2017.
//

#ifndef ECHEC_PLAYER_H
#define ECHEC_PLAYER_H


#include <vector>
#include <map>
#include "Piece.h"
#include "King.h"

class Player {

    private:
        int m_id;
        std::map< Piece *, bool > m_army;

    public:
        Player(int id);
        int getId();
        std::map< Piece *, bool > & getArmy();
        King * getKing();
        Piece * piece(Position position);
        std::vector< Piece * > alive();
        std::vector< Piece * > dead();
        std::vector<Piece *> classement()const;




};


#endif //ECHEC_PLAYER_H
