//
// Created by Mathieu on 26/12/2017.
//

#include "Check.h"

Check::Check():m_description("Check !") {}

const char* Check::what() const throw(){
    return  m_description;
}
