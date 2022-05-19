//
// Created by Raul on 5/18/2022.
//

#include "../Headers/InvalidPriceException.h"
#include <string>
#include <cstring>

InvalidPriceException::InvalidPriceException(int paramUnderLimitPrice) {

    this->underLimitPrice = paramUnderLimitPrice;

}

const char* InvalidPriceException::what() const noexcept {

    std::string msg = "Pretul introdus este prea mic, pretul minim este de 1 leu!\n";

    char* copyMsg = new char[msg.length() + 1];
    strcpy_s(copyMsg, msg.length() + 1, msg.c_str());

    const char* res = const_cast<char*>(copyMsg);

    return res;

}