//
// Created by Raul on 5/18/2022.
//

#ifndef LAB10_NEGATIVEIDEXCEPTION_H
#define LAB10_NEGATIVEIDEXCEPTION_H


class NegativeIdException {
public:
    NegativeIdException();

    const char* what() const noexcept;
};


#endif //LAB10_NEGATIVEIDEXCEPTION_H
