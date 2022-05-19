//
// Created by Raul on 5/11/2022.
//

#include "../Headers/ProductValidator.h"


ProductValidator::ProductValidator(int paramUnderLimitPrice) {

    this->underLimitPrice = paramUnderLimitPrice;

}

bool ProductValidator::validate(int price, int id) {

    if(price < this->underLimitPrice)
        throw new InvalidPriceException(price);

    if(id < 0)
        throw new NegativeIdException;

    return true;
}