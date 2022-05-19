//
// Created by Raul on 5/10/2022.
//

#ifndef LAB10_USERINTERFACE_H
#define LAB10_USERINTERFACE_H

#include "../Service/ProductService.h"

class UserInterface {
private:
    ProductService service;
public:

    UserInterface(const ProductService&);
    ~UserInterface();

    static void showManagerConsole();
    int runManagerConsole();

    static void showUserConsole();
    int runUserConsole();

    int runConsole();
};

#endif //LAB10_USERINTERFACE_H
