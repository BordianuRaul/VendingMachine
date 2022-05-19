//
// Created by Raul on 5/14/2022.
//

#include <cstring>
#include <string>
#include "../Headers/NotEnoughMoneyException.h"

NotEnoughMoneyException::NotEnoughMoneyException() = default;

const char* NotEnoughMoneyException::what() const noexcept{

    std::string msg = "Nu se poate achizitiona produsul! Suma de bani introdusa este insuficienta!\n";

    char* copyMsg = new char[msg.length() + 1];
    strcpy_s(copyMsg, msg.length() + 1, msg.c_str());

    const char* res = const_cast<char*>(copyMsg);

    return res;

}