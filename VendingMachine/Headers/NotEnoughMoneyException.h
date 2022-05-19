//
// Created by Raul on 5/14/2022.
//

#ifndef LAB10_NOTENOUGHMONEYEXCEPTION_H
#define LAB10_NOTENOUGHMONEYEXCEPTION_H

#include <exception>

class NotEnoughMoneyException: public std::exception {
public:

    NotEnoughMoneyException();

    const char* what() const noexcept;

};


#endif //LAB10_NOTENOUGHMONEYEXCEPTION_H
