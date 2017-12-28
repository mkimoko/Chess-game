//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_OBSTRUCTION_H
#define CHESS_OBSTRUCTION_H

#include <exception>
#include <string>

class Obstruction : public std::exception{
private:
    const char* m_description;
public:
    Obstruction();
    const char *what() const throw();


};


#endif //CHESS_OBSTRUCTION_H
