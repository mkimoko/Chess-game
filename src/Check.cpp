//
// Created by Mathieu on 28/12/2017.
//

#include "../includes/exception/Check.h"

Check::Check():m_description("Check !") {}

const char* Check::what() const throw(){
    return  m_description;
}

