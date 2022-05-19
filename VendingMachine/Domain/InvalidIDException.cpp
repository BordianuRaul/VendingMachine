//
// Created by Raul on 5/15/2022.
//

#include "../Headers/InvalidIDException.h"
#include <cstring>
#include <string>


InvalidIDException::InvalidIDException() = default;

const char* InvalidIDException::what() const noexcept {

    std::string msg = "Nu exista un produs cu acest ID!";

    char* copyMsg = new char[msg.length() + 1];
    strcpy_s(copyMsg, msg.length() + 1, msg.c_str());

    const char* res = const_cast<char*>(copyMsg);

    return res;

}
