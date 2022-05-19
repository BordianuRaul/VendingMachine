//
// Created by Raul on 5/15/2022.
//

#ifndef LAB10_INVALIDIDEXCEPTION_H
#define LAB10_INVALIDIDEXCEPTION_H

#include <exception>

class InvalidIDException: public std::exception{
public:
    InvalidIDException();

    const char* what() const noexcept;
};


#endif //LAB10_INVALIDIDEXCEPTION_H
