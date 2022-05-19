//
// Created by Raul on 5/18/2022.
//

#ifndef LAB10_INVALIDPRICEEXCEPTION_H
#define LAB10_INVALIDPRICEEXCEPTION_H


class InvalidPriceException {
private:
    int underLimitPrice;
public:

    InvalidPriceException(int);

    const char* what() const noexcept;
};


#endif //LAB10_INVALIDPRICEEXCEPTION_H
