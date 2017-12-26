//
// Created by Mathieu on 26/12/2017.
//

#ifndef ECHEC_OUT_OF_BOARD_H
#define ECHEC_OUT_OF_BOARD_H

#include <string>
#include <exception>

class Out_of_Board : public std::exception{
    private:
        const std::string & m_description;
    public:
        Out_of_Board(  );
        const char *what() const throw();


};


#endif //ECHEC_OUT_OF_BOARD_H
