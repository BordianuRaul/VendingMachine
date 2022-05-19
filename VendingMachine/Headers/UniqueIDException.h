//
// Created by Raul on 5/15/2022.
//

#ifndef LAB10_UNIQUEIDEXCEPTION_H
#define LAB10_UNIQUEIDEXCEPTION_H

#include <exception>

class UniqueIDException: public std::exception{
public:
    UniqueIDException();

    const char* what() const noexcept;
};


#endif //LAB10_UNIQUEIDEXCEPTION_H
