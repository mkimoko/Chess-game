//
// Created by Mathieu on 28/12/2017.
//

#include "../includes/exception/Check_Mate.h"

Check_Mate::Check_Mate():m_description("Check Mate!\n") {}

const char* Check_Mate::what() const throw(){
    return  m_description;
}