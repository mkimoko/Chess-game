//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_OUT_OF_BOARD_H
#define CHESS_OUT_OF_BOARD_H

#include <string>
#include <exception>

class Out_of_Board : public std::exception{
private:
    const char* m_description;
public:
    Out_of_Board(  );
    const char *what() const throw();

};

#endif //CHESS_OUT_OF_BOARD_H
