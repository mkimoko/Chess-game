//
// Created by Mathieu on 26/12/2017.
//

#ifndef ECHEC_CHECK_H
#define ECHEC_CHECK_H


#include <exception>
#include <string>

class Check : public std::exception{
    private:
        const std::string & m_description;
    public:
        Check();
        const char *what() const throw();


};


#endif //ECHEC_CHECK_H
