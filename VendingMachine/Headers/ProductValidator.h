//
// Created by Raul on 5/11/2022.
//

#ifndef LAB10_PRODUCTVALIDATOR_H
#define LAB10_PRODUCTVALIDATOR_H

#include "../Headers/InvalidPriceException.h"
#include "../Headers/NegativeIdException.h"
#include <exception>

using namespace std;

class ProductValidator: public exception {
private:

    int underLimitPrice;

public:

    ProductValidator(int);

    bool validate(int, int);

};


#endif //LAB10_PRODUCTVALIDATOR_H
