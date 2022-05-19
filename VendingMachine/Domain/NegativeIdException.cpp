//
// Created by Raul on 5/18/2022.
//

#include "../Headers/NegativeIdException.h"
#include <cstring>
#include <string>

NegativeIdException::NegativeIdException() = default;

const char* NegativeIdException::what() const noexcept {

    std::string msg = "Id-ul introdus nu este valid! Id-ul ar trebui sa aiba o valoare mai mare decat 0.\n";

    char* copyMsg = new char[msg.length() + 1];
    strcpy_s(copyMsg, msg.length() + 1, msg.c_str());

    const char* res = const_cast<char*>(copyMsg);

    return res;

}