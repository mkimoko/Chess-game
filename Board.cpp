//
// Created by Mathieu on 24/12/2017.
//

#include "Board.h"
#include "Pawn.h"
#include "No_Piece.h"
#include "Obstruction.h"
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
                        it->first->operator()();std::cout <<m_p2.getId()<< "\t";
                        test1 = m_p2.piece(Position(k,j));
                    }
                }
            }

            for (it = m_p1.getArmy().begin(); it != m_p1.getArmy().end(); it++ ){

                if (it->second == true){
                    if (it->first->getPosition().getCol() == k  && it->first->getPosition().getRow() == j){
                        it->first->operator()();std::cout <<m_p1.getId()<< "\t";
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
    std::cout<<"\n\n ";
}

Piece * Board::piece(Position position){

    if (m_p1.piece(position) != nullptr)
        return m_p1.piece(position);

    if (m_p2.piece(position) != nullptr)
        return m_p2.piece(position);

    return nullptr;
}

Player & Board::getPlayer1(){
    return m_p1;
}

Player & Board::getPlayer2(){
    return m_p2;
}

void Board::deplacement(int id,Position start, Position end){
    Piece * p ;
    try {

        if (id == 1)
            p = m_p1.piece(start);

        if (id == 2)
            p = m_p2.piece(start);

        if (p->deplacement(end) == 1){
            if (accessibility(p, end) == true){
                p->getPosition().placement(end.getCol(),end.getRow());
            }
            else{
                throw Obstruction();
            }
        }else{
            throw Obstruction();
        }

    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

}

bool Board::accessibility(Piece * piece, Position p){
    if (piece->getCode() == 1){
        //std::cout << "Piece";
        return accessibility( (Pawn *)piece, p);
    }

    if (piece->getCode() == 2){
        //std::cout << "Piece";
        return accessibility( (Rook *)piece, p);
    }

    if (piece->getCode() == 3){
        //std::cout << "Piece";
        return accessibility( (Bishop *)piece, p);
    }

    if (piece->getCode() == 4){
        return accessibility((Knight *) piece, p);
    }
}

bool Board::accessibility(Pawn * pawn, Position p){
    if (pawn->deplacement(p) == 1){
        //std::cout << "Pion";
        try {
            piece(p); /*Regarde si il n'y  a pas de piece*/
        }
        catch (const std::exception &e){
            return true;
        }
    }
    return false;
}

bool Board::accessibility(Rook *rook, Position p){
    if (rook->deplacement(p) == 1){
        try {
            piece(p);
        }catch (const std::exception &e){

            if (rook->getPosition().getCol()+1 == p.getCol() || rook->getPosition().getCol()-1 == p.getCol())
                return true;
            if (rook->getPosition().getRow()+1 == p.getRow() || rook->getPosition().getRow()-1 == p.getCol())
                return true;

            if (rook->getPosition().getCol() < p.getCol())
                return accessibility(rook, Position (p.getCol()+1, p.getRow()));
            if (rook->getPosition().getCol() > p.getCol())
                return accessibility(rook, Position (p.getCol()-1, p.getRow()));

            if (rook->getPosition().getRow() < p.getRow())
                return accessibility(rook, Position (p.getCol(), p.getRow()+1));
            if (rook->getPosition().getCol() > p.getCol())
                return accessibility(rook, Position (p.getCol(), p.getRow()-1));
        }

    }
    return false;
}

bool Board::accessibility(Bishop * bishop, Position p){
    if (bishop->deplacement(p) == 1){
        try {
            piece(p);
        }catch (const std::exception &e){

            if (bishop->getPosition().getCol() < p.getCol()){
                if (bishop->getPosition().getRow() < p.getRow()){
                    if (bishop->getPosition().getCol()+1 == p.getCol()){
                        if (bishop->getPosition().getRow()+1 == p.getRow()){
                            return true;
                        }

                    }
                    //std::cout<<"new tour +1+1";
                    Position(p.getCol()-1, p.getRow()-1)();
                    return accessibility(bishop, Position(p.getCol()-1, p.getRow()-1));
                }

                if (bishop->getPosition().getRow() > p.getRow()){
                    if (bishop->getPosition().getCol()+1 == p.getCol()){
                        if (bishop->getPosition().getRow()-1 == p.getRow()){
                            return true;
                        }

                    }
                    return accessibility(bishop, Position(p.getCol()-1, p.getRow()+1));
                }

            }

            if (bishop->getPosition().getCol() > p.getCol()){
                if (bishop->getPosition().getRow() < p.getRow()){
                    if (bishop->getPosition().getCol()-1 == p.getCol()){
                        if (bishop->getPosition().getRow()+1 == p.getRow()){
                            return true;
                        }

                    }
                    return accessibility(bishop, Position(p.getCol()+1, p.getRow()-1));
                }

                if (bishop->getPosition().getRow() > p.getRow()){
                    if (bishop->getPosition().getCol()-1 == p.getCol()){
                        if (bishop->getPosition().getRow()-1 == p.getRow()){
                            std::cout<<"-1-1";
                            return true;
                        }
                    }
                    return accessibility(bishop, Position(p.getCol()+1, p.getRow()+1));
                }

            }
        }
    }
    return false;
}

bool Board::accessibility(Knight * knight, Position p){
    if (knight->deplacement(p) == 1){
        try {
            piece(p);
        }catch (const std::exception &e){
            return true;
        }

    }
    std::cout << "bijour";
    return false;
}