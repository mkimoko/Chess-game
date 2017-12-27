//
// Created by Mathieu on 26/12/2017.
//

#include "Check_Mate.h"

Check_Mate::Check_Mate():m_description("Check Mate!") {}

const char* Check_Mate::what() const throw(){
    return  m_description;
}