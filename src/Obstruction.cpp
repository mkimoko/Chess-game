//
// Created by Mathieu on 28/12/2017.
//

#include "../includes\exception\Obstruction.h"

Obstruction::Obstruction():m_description("\nYou can't go there...\n") {}

const char* Obstruction::what() const throw(){
    return  m_description;
}

