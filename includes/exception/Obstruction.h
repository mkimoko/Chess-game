//
// Created by Mathieu on 26/12/2017.
//

#ifndef ECHEC_OBSTRUCT_EXCEPTION_H
#define ECHEC_OBSTRUCT_EXCEPTION_H


#include <exception>
#include <string>

class Obstruction : public std::exception{
    private:
        const char* m_description;
    public:
        Obstruction();
        const char *what() const throw();


};


#endif //ECHEC_OBSTRUCT_EXCEPTION_H
