//
// Created by Mathieu on 26/12/2017.
//

#include "Out_of_Board.h"

Out_of_Board::Out_of_Board() :m_description("Position you choose is out of the board") {}

const char *Out_of_Board::what() const throw(){
    return  m_description.c_str();
}
