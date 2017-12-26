//
// Created by Mathieu on 24/12/2017.
//

#ifndef ECHEC_BOARD_H
#define ECHEC_BOARD_H


#include "Player.h"

class Board {

    private:
        Player m_p1;
        Player m_p2;

    public:
        Board();
        void printTab();

};


#endif //ECHEC_BOARD_H
