//
// Created by Raul on 5/10/2022.
//

#ifndef LAB10_PRODUCT_H
#define LAB10_PRODUCT_H

#include <ostream>

class Product {
private:
    int id;
    char* name;
    int price;
public:
    Product();

    Product(int, char*, int);

    Product(Product&);

    ~Product();

    int getId() const;

    int getPrice() const;

    char* getName() const;

    void setId(int);

    void setPrice(int);

    void setName(char*);

    bool operator==(const Product&);

    Product& operator=(const Product&);

    bool operator!=(const Product &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Product &product);
    friend std::istream &operator>>(std::istream &is, Product &product);
};

#endif //LAB10_PRODUCT_H
