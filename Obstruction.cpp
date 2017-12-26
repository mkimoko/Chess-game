//
// Created by Mathieu on 26/12/2017.
//

#include "Obstruction.h"

Obstruction::Obstruction():m_description("You can't go there...\nThere is another piece between your position and the one you want to go") {}

const char* Obstruction::what() const throw(){
    return  m_description.c_str();
}