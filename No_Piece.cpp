//
// Created by Mathieu on 26/12/2017.
//

#include "No_Piece.h"

No_Piece::No_Piece():m_description("There is no piece in this position or the piece here is not yours") {}

const char *No_Piece::what() const throw(){
    return m_description;
}
