//
// Created by Raul on 5/10/2022.
//


#include "ProductService.h"
#include "../Headers/NotEnoughMoneyException.h"
#include "../Headers/InvalidIDException.h"
#include "../Headers/UniqueIDException.h"


ProductService::ProductService() {

    char* fileName = new char[13];
    strcpy_s(fileName, 13, "TestRepo.txt");

    this->repo.setFileName(fileName);

    delete[] fileName;

    this->banknotes.insert(pair<int, int>(1, 0));
    this->banknotes.insert(pair<int, int>(5, 0));
    this->banknotes.insert(pair<int, int>(10, 0));
    this->banknotes.insert(pair<int, int>(50, 0));
    this->banknotes.insert(pair<int, int>(100, 0));
    this->banknotes.insert(pair<int, int>(200, 0));
    this->banknotes.insert(pair<int, int>(500, 0));

}

ProductService::ProductService(const FileRepository<Product>& paramRepo, map<int, int> paramBanknotes){

    this->repo = paramRepo;
    this->banknotes.insert(paramBanknotes.begin(), paramBanknotes.end());

}

ProductService::ProductService(ProductService& paramProductService) {

    this->repo = paramProductService.repo;
    this->banknotes.insert(paramProductService.banknotes.begin(), paramProductService.banknotes.end());

}

ProductService::~ProductService() {

    this->banknotes.erase(this->banknotes.begin(), this->banknotes.end());
}

FileRepository<Product> ProductService::getFileRepo() const {
    return this->repo;
}

const map<int, int> &ProductService::getBanknotes() const {
    return this->banknotes;
}

void ProductService::setRepo(const FileRepository<Product> &paramRepo) {
    ProductService::repo = paramRepo;
}

void ProductService::setBanknotes(const map<int, int> &paramBanknotes) {

    this->banknotes.erase(this->banknotes.begin(), this->banknotes.end());
    this->banknotes.insert(paramBanknotes.begin(), paramBanknotes.end());

}

void ProductService::createElem(int id, char* name, int price) {

    int numberOfProducts = this->repo.getNumberOfEntities();

    for(int i = 0; i < numberOfProducts; i++)
    {
        if(this->repo.getEntities()[i].getId() == id)
            throw new UniqueIDException();
    }

    Product createProduct(id, name, price);

    this->repo.addElemFile(createProduct);

}

Product ProductService::readElem(int paramId) {

    int numberOfProducts = this->repo.getNumberOfEntities();

    for(int i = 0; i < numberOfProducts; i++)
    {
        if(this->repo.getEntities()[i].getId() == paramId)
            return this->repo.getEntities()[i];
    }

    throw new InvalidIDException();

}

void ProductService::updateElem(int id, char* name, int price) {

    int numberOfProducts = this->repo.getNumberOfEntities();
    int i;

    for(i = 0; i < numberOfProducts; i++)
    {
        if(this->repo.getEntities()[i].getId() == id)
        {
            this->repo.getEntities()[i].setName(name);
            this->repo.getEntities()[i].setPrice(price);
            break;
        }
    }

    if(i == numberOfProducts)
        throw new InvalidIDException();
}

void ProductService::deleteElem(int id) {


    int numberOfProducts = this->repo.getNumberOfEntities();
    int i;

    for(i = 0; i < numberOfProducts; i++)
    {
        if(this->repo.getEntities()[i].getId() == id)
        {
            this->repo.deleteElem(this->repo.getEntities()[i]);
            break;
        }
    }

    if(i == numberOfProducts)
        throw new InvalidIDException();


}

int ProductService::totalSum() {

    int sum = 0;

    map<int, int>::iterator itr;

    for(itr = this->banknotes.begin(); itr != this->banknotes.end(); itr++)
        sum = sum + (itr->first * itr->second);

    return sum;

}

ProductService& ProductService::operator=(const ProductService &rhs) {

    setRepo(rhs.repo);
    setBanknotes(rhs.banknotes);

    return *this;

}

Product ProductService::getProductByID(int paramID) {

    int numberOfProducts = this->repo.getNumberOfEntities();

    for(int i = 0; i < numberOfProducts; i++)
    {
        if(this->repo.getEntities()[i].getId() == paramID)
            return this->repo.getEntities()[i];
    }

    throw new InvalidIDException();
}

void ProductService::buyProduct(map<int,int> paramBanknotes) {

    map<int, int>::iterator paramItr;
    map<int, int>::iterator itr;

    for(itr = this->banknotes.begin(), paramItr = paramBanknotes.begin(); itr != this->banknotes.end();
    itr++, paramItr++)
    {
        itr->second += paramItr->second;
    }

}

bool ProductService::isChange(int change) {

    if(change < 0)
        throw new NotEnoughMoneyException();

    map<int, int>::reverse_iterator itr;

    for(itr = this->banknotes.rbegin(); itr != this->banknotes.rend() && change > 0; itr++)
    {
        int banknote = itr->first;
        int numberOfBanknotes = itr->second;

        while(numberOfBanknotes)
        {
            if(change - (numberOfBanknotes * banknote) < 0)
                numberOfBanknotes--;
            else{
                change -= banknote * numberOfBanknotes;
                break;
            }
        }
    }

    if(change == 0)
        return true;
    else return false;

}

map<int, int> ProductService::giveChange(int change) {


    map<int, int> giveChange;
    map<int, int>::iterator itr;

    for(itr = this->banknotes.begin(); itr != this->banknotes.end(); itr++)
    {
        int banknote = itr->first;
        int numberOfBanknotes = itr->second;

        while(numberOfBanknotes)
        {
            if(change - (numberOfBanknotes * banknote) < 0)
                numberOfBanknotes--;
            else{
                giveChange.insert(pair<int, int>(banknote, numberOfBanknotes));
                change -= banknote * numberOfBanknotes;
                itr->second -= numberOfBanknotes;
                break;
            }
        }
    }

    return giveChange;

}
