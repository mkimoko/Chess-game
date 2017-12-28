//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_CHECK_MATE_H
#define CHESS_CHECK_MATE_H

#include <exception>
#include <string>
class Check_Mate : public std::exception {
private:
    const char * m_description;
public:
    Check_Mate();
    const char *what() const throw();
};

#endif //CHESS_CHECK_MATE_H
