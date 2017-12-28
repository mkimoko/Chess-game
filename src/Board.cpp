//
// Created by Mathieu on 28/12/2017.
//

#include "../includes/Board.h"
#include "../includes/Pawn.h"
#include "../includes/exception/No_Piece.h"
#include "../includes/exception/Obstruction.h"
#include "../includes/exception/Check.h"
#include <iostream>
#include <string>
#include <getopt.h>

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

bool Board::deplacement(int id, Position start, Position end){
    Piece * p ;
    try {

        std::map<Piece *, bool >::iterator it;
        if (id == 1){
            p = m_p1.piece(start);
            for (it = m_p1.getArmy().begin(); it != m_p1.getArmy().end(); it++) {
                if (it->first == p)
                    if (it->second == false)
                        throw No_Piece();
            }
        }


        if (id == 2){
            p = m_p2.piece(start);
            for (it = m_p2.getArmy().begin(); it != m_p2.getArmy().end(); it++) {
                if (it->first == p)
                    if (it->second == false)
                        throw No_Piece();
            }
        }


        if (p->deplacement(end,id) == 1){
            if (accessibility(p, end, id) == true){
                p->getPosition().placement(end.getCol(),end.getRow());
                if (p->getCode() == 5){
                    Queen* q = (Queen *) p;
                    q->positionement(end);
                }
                return true;
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
    return false;
}

bool Board::kill(int id, Position start, Position end){
    Piece *p;

    try {
        if (id == 1)
            p = m_p1.piece(start);

        if (id == 2)
            p = m_p2.piece(start);

        if (p->kill(piece(end), id) == 1){
            if (accessibility(p, end, id) == false){
                p->getPosition().placement(end.getCol(),end.getRow());
                if (p->getCode() == 5){
                    Queen* q = (Queen *) p;
                    q->positionement(end);
                }

                std::map<Piece *, bool>::iterator it;
                if (id == 1){
                    for(it = m_p2.getArmy().begin(); it != m_p2.getArmy().end(); it++){
                        if (it->first->getPosition() == end){
                            it->second = false;
                        }
                    }
                }

                if (id == 2){
                    for(it = m_p1.getArmy().begin(); it != m_p1.getArmy().end(); it++){
                        if (it->first->getPosition() == end){
                            it->second = false;
                        }
                    }
                }
                return true;
            }
            else{
                throw No_Piece();
            }
        }else{
            throw No_Piece();
        }

    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return false;
}

bool Board::accessibility(Piece * piece, Position p, int option){
    if (piece->getCode() == 1){
        return accessibility( (Pawn *)piece, p, option);
    }

    if (piece->getCode() == 2){
        return accessibility( (Rook *)piece, p, option);
    }

    if (piece->getCode() == 3){
        return accessibility( (Bishop *)piece, p, option);
    }

    if (piece->getCode() == 4){
        return accessibility((Knight *) piece, p, option);
    }

    if (piece->getCode() == 5){
        return accessibility((Queen *) piece, p, option);
    }

    if (piece->getCode() == 6){
        return accessibility((King *) piece, p, option);
    }
}

bool Board::accessibility(Pawn * pawn, Position p, int option){
    if (pawn->deplacement(p, option) == 1){
        try {
            piece(p); /*Check if there is a piece at this position*/
        }
        catch (const std::exception &e){
            /*if not */return true;
        }
    }
    return false;
}

bool Board::accessibility(Rook *rook, Position p, int option){
    if (rook->deplacement(p,option) == 1){
        try {
            piece(p);
        }catch (const std::exception &e){

            if (rook->getPosition().getCol()+1 == p.getCol() || rook->getPosition().getCol()-1 == p.getCol())
                return true;
            if (rook->getPosition().getRow()+1 == p.getRow() || rook->getPosition().getRow()-1 == p.getCol())
                return true;

            if (rook->getPosition().getCol() < p.getCol())
                return accessibility(rook, Position (p.getCol()+1, p.getRow()), option);
            if (rook->getPosition().getCol() > p.getCol())
                return accessibility(rook, Position (p.getCol()-1, p.getRow()), option);

            if (rook->getPosition().getRow() < p.getRow())
                return accessibility(rook, Position (p.getCol(), p.getRow()+1), option);
            if (rook->getPosition().getCol() > p.getCol())
                return accessibility(rook, Position (p.getCol(), p.getRow()-1), option);
        }

    }
    return false;
}

bool Board::accessibility(Bishop * bishop, Position p, int option){
    if (bishop->deplacement(p, option) == 1){
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
                    return accessibility(bishop, Position(p.getCol()-1, p.getRow()-1), option);
                }

                if (bishop->getPosition().getRow() > p.getRow()){
                    if (bishop->getPosition().getCol()+1 == p.getCol()){
                        if (bishop->getPosition().getRow()-1 == p.getRow()){
                            return true;
                        }

                    }
                    return accessibility(bishop, Position(p.getCol()-1, p.getRow()+1), option);
                }

            }

            if (bishop->getPosition().getCol() > p.getCol()){
                if (bishop->getPosition().getRow() < p.getRow()){
                    if (bishop->getPosition().getCol()-1 == p.getCol()){
                        if (bishop->getPosition().getRow()+1 == p.getRow()){
                            return true;
                        }

                    }
                    return accessibility(bishop, Position(p.getCol()+1, p.getRow()-1), option);
                }

                if (bishop->getPosition().getRow() > p.getRow()){
                    if (bishop->getPosition().getCol()-1 == p.getCol()){
                        if (bishop->getPosition().getRow()-1 == p.getRow()){
                            return true;
                        }
                    }
                    return accessibility(bishop, Position(p.getCol()+1, p.getRow()+1), option);
                }

            }
        }
    }
    return false;
}

bool Board::accessibility(Knight * knight, Position p, int option){
    if (knight->deplacement(p, option) == 1){
        try {
            piece(p);
        }catch (const std::exception &e){
            return true;
        }

    }
    return false;
}

bool Board::accessibility(Queen * queen, Position p, int option){
    if(queen->deplacement(p, option) == 1){
        try {
            piece(p);
        }catch (const std::exception &e){

            if (accessibility(& queen->getBishop(),p, option) == true){
                return accessibility(& queen->getBishop(),p, option);
            }


            if (accessibility(& queen->getRook(),p, option) == true){
                return accessibility(& queen->getRook(),p, option);
            }

        }
    }
    return false;
}

bool Board::accessibility(King * king, Position p, int option){
    if (king->deplacement(p, option) == 1){
        try {
            piece(p);
        }catch (const std::exception &e){
            return true;
        }
    }
    return false;
}

bool Board::threatned(int id){
    std::map<Piece *, bool>::iterator it;

    if (id == 1){
        for (it = m_p2.getArmy().begin(); it != m_p2.getArmy().end(); it++ ){
            if(it->first->kill(m_p1.getKing(), 0) == 1)
                throw Check();
        }
    }

    if (id == 2){
        for (it = m_p1.getArmy().begin(); it != m_p1.getArmy().end(); it++ ){
            if(it->first->kill(m_p2.getKing(), 0) == 1)
                throw Check();
        }
    }

    return false;

}

bool Board::win(int id) {
    try {
        threatned(id);
    }catch (const std::exception &e){


        try {
            deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()-1,m_p1.getKing()->getPosition().getRow()-1 ) );
            threatned(id);
        }catch (const std::exception &e){
            try {

            }catch (const std::exception &e){
                deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()+1,m_p1.getKing()->getPosition().getRow()+1 ) );
                deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()-1,m_p1.getKing()->getPosition().getRow() ) );
                threatned(id);

                try {
                    deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()+1,m_p1.getKing()->getPosition().getRow() ) );
                    deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()-1,m_p1.getKing()->getPosition().getRow()+1 ) );
                    threatned(id);


                }catch (const std::exception &e){
                    deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()+1,m_p1.getKing()->getPosition().getRow()-1 ) );
                    deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()-1,m_p1.getKing()->getPosition().getRow()+1 ) );
                    threatned(id);

                    try {
                        deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()+1,m_p1.getKing()->getPosition().getRow()-1 ) );
                        deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol(),m_p1.getKing()->getPosition().getRow()+1 ) );
                        threatned(id);

                    }catch (const std::exception &e){
                        try {
                            deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol(),m_p1.getKing()->getPosition().getRow()-1 ) );
                            deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()+1,m_p1.getKing()->getPosition().getRow()+1 ) );
                            threatned(id);


                        }catch (const std::exception &e){
                            deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()-1,m_p1.getKing()->getPosition().getRow()-1 ) );
                            deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()+1,m_p1.getKing()->getPosition().getRow() ) );
                            threatned(id);

                            try {
                                deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()-1,m_p1.getKing()->getPosition().getRow() ) );
                                deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()+1,m_p1.getKing()->getPosition().getRow()-1 ) );
                                threatned(id);


                            }catch (const std::exception &e){
                                try {
                                    deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol()-1,m_p1.getKing()->getPosition().getRow()+1 ) );
                                    deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol(),m_p1.getKing()->getPosition().getRow()-1 ) );
                                    threatned(id);

                                    deplacement(id, m_p1.getKing()->getPosition(), Position(m_p1.getKing()->getPosition().getCol(),m_p1.getKing()->getPosition().getRow()+1 ) );
                                }catch (const std::exception &e){
                                    return true;
                                }


                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}