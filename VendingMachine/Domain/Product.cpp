//
// Created by Raul on 5/10/2022.
//


#include "../Headers/Product.h"
#include <cstring>
#include <iostream>

Product::Product() {
    this->id = -1;
    this->name = nullptr;
    this->price = 0;
}

Product::Product(int paramId, char * paramName, int paramPrice) {

    this->id = paramId;
    this->name = new char[strlen(paramName) + 1];
    strcpy_s(this->name, strlen(paramName) + 1, paramName);
    this->price = paramPrice;

}

Product::Product(Product & paramProduct) {

    this->id = paramProduct.getId();
    this->name = new char[strlen(paramProduct.getName()) + 1];
    strcpy_s(this->name, strlen(paramProduct.getName()) + 1, paramProduct.getName());
    this->price = paramProduct.getPrice();

}

Product::~Product() {
    delete[] this->name;
    this->name = nullptr;
}

int Product::getId() const {
    return this->id;
}

int Product::getPrice() const {
    return this->price;
}

char* Product::getName() const {
    return this-> name;
}

void Product::setPrice(int paramPrice) {
    Product::price = paramPrice;
}

void Product::setName(char * paramName) {

    if(this->name != nullptr)
    {
        delete[] this->name;
        this->name = nullptr;
    }
    this->name = new char[strlen(paramName) + 1];
    strcpy_s(this->name, strlen(paramName) + 1, paramName);
}

void Product::setId(int paramId) {
    this->id = paramId;
}

bool Product::operator==(const Product& paramProduc) {

    if(this->id != paramProduc.getId())
        return false;

    if(strcmp(this->name, paramProduc.getName()) != 0)
        return false;

    if(this->price != paramProduc.getPrice())
        return false;

    return true;

}

Product& Product::operator=(const Product &paramProduct) {

    if(this == &paramProduct)
        return *this;

    setId(paramProduct.getId());
    setName(paramProduct.getName());
    setPrice(paramProduct.getPrice());

    return *this;

}

bool Product::operator!=(const Product &rhs) const {

    if(this->id == rhs.getId())
        return false;

    if(strcmp(this->name, rhs.getName()) == 0)
        return false;

    if(this->price == rhs.getPrice())
        return false;

    return true;

}

std::ostream &operator<<(std::ostream &os, const Product &product) {
    os << product.id <<  " " << product.name << " " << product.price << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Product &product){

    int id;

    is >> id;

    char* name = new char[20];

    is >> name;

    int price;

    is >> price;

    product.setId(id);
    product.setName(name);
    product.setPrice(price);

    return is;
}
