//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_NO_PIECE_H
#define CHESS_NO_PIECE_H

#include <string>
#include <exception>

class No_Piece : public std::exception{
private:
    const char * m_description;

public:
    No_Piece();
    const char *what() const throw();

};


#endif //CHESS_NO_PIECE_H
