//
// Created by Mathieu on 23/12/2017.
//

#ifndef ECHEC_PLAYER_H
#define ECHEC_PLAYER_H


#include <vector>
#include "Piece.h"

class Player {

    private:
        int m_id;
        std::vector<Piece> m_army;

    public:
        Player(int id);
        std::vector<Piece> & getArmy();
        Piece & piece(Position position);
};


#endif //ECHEC_PLAYER_H
