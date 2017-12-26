//
// Created by Mathieu on 24/12/2017.
//

#include "Board.h"
#include "Pawn.h"
#include <iostream>
#include <string>

Board::Board(): m_p1(1), m_p2(2) {}

void Board::printTab() {
    char col = 'A';
    std::map<Piece *, bool>::iterator it;
    Piece * test1 = nullptr;
    Piece *test2 = nullptr;
    std::cout << "\n\t\t";
    for (int i=0; i<8; i++){
        std::cout<< (char)(col+i)<<"\t";
    }
    std::cout<<"\n\n\n";

    //--------------------lignes---------------------------
    for (int j = 8; j >=1 ; j--) {
        std::cout << "\t"<< j<<"\t";

        //------------------colones------------------------
        for (int k = 1; k <=8 ; k++) {

            for (it = m_p2.getArmy().begin(); it != m_p2.getArmy().end(); it++ ){

                if (it->second == true){
                    if (it->first->getPosition().getCol() == k  && it->first->getPosition().getRow() == j){
                        it->first->operator()();std::cout << "\t";
                        test1 = m_p2.piece(Position(k,j));
                    }
                }
            }

            for (it = m_p1.getArmy().begin(); it != m_p1.getArmy().end(); it++ ){

                if (it->second == true){
                    if (it->first->getPosition().getCol() == k  && it->first->getPosition().getRow() == j){
                        it->first->operator()();std::cout << "\t";
                        test1 = m_p1.piece(Position(k,j));
                    }
                }
            }
            if (test1 == nullptr && test2 == nullptr )
                std::cout <<"\t";

            test1 = nullptr;
            test2 = nullptr;
        }
        std::cout << j<<"\t\n";
        std::cout<<std::endl;

    }

    std::cout << "\n\t\t";
    for (int i=0; i<8; i++){
        std::cout<< (char)(col+i)<<"\t";
    }

}
