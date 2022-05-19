//
// Created by Raul on 5/10/2022.
//

#ifndef LAB10_PRODUCTSERVICE_H
#define LAB10_PRODUCTSERVICE_H

#include "../Headers/Product.h"
#include "../Repository/FileRepository.h"
#include <map>
#include <iterator>

using namespace std;

class ProductService {
private:
    FileRepository<Product> repo;
    map<int, int> banknotes;
public:

    ProductService();

    ProductService(const FileRepository<Product>&, map<int, int>);

    ProductService(ProductService&);

    ~ProductService();

    FileRepository<Product> getFileRepo() const;

    const map<int, int> &getBanknotes() const;

    void setRepo(const FileRepository<Product> &repo);

    void setBanknotes(const map<int, int> &banknotes);

    void createElem(int, char*, int);

    Product readElem(int);

    void updateElem(int, char*, int);

    void deleteElem(int);

    int totalSum();

    ProductService& operator=(const ProductService &);

    void buyProduct(map<int, int>);

    bool isChange(int);

    map<int, int> giveChange(int);

    Product getProductByID(int);
};



#endif //LAB10_PRODUCTSERVICE_H
