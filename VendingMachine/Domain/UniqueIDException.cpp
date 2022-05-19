//
// Created by Raul on 5/15/2022.
//

#include "../Headers/UniqueIDException.h"
#include <cstring>
#include <string>

UniqueIDException::UniqueIDException() = default;

const char* UniqueIDException::what() const noexcept {

    std::string msg = "ID-ul introdus deja exista!";

    char* copyMsg = new char[msg.length() + 1];
    strcpy_s(copyMsg, msg.length() + 1, msg.c_str());

    const char* res = const_cast<char*>(copyMsg);

    return res;

}