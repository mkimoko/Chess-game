//
// Created by Mathieu on 26/12/2017.
//

#ifndef ECHEC_NO_PIECE_H
#define ECHEC_NO_PIECE_H

#include <string>
#include <exception>

class No_Piece : public std::exception{
    private:
        const char * m_description;

public:
        No_Piece();
        const char *what() const throw();

};


#endif //ECHEC_NO_PIECE_H
