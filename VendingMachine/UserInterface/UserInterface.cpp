//
// Created by Raul on 5/2/2022.
//

#include "UserInterface.h"
#include "../Headers/NotEnoughMoneyException.h"
#include "../Headers/InvalidIDException.h"
#include "../Headers/UniqueIDException.h"
#include "../Headers/ProductValidator.h"
#include <iostream>

using namespace std;

UserInterface::UserInterface(const ProductService& paramProductService){

    this->service = paramProductService;

}
UserInterface::~UserInterface() = default;

void UserInterface::showManagerConsole() {

    cout << "1.Adaugare produs." << endl;
    cout << "2.Afisare produs." << endl;
    cout << "3.Modificare produs." << endl;
    cout << "4.Stergere produs." << endl;
    cout << "5.Afisare produse." << endl;
    cout << "0.Iesire din program." << endl;

}

void UserInterface::showUserConsole() {

    cout << "1.Afisare produse." << endl;
    cout << "2.Cumpara produs." << endl;
    cout << "0.Iesire program." << endl;

}

int UserInterface::runManagerConsole() {

    while(true){

        showManagerConsole();

        int option;

        cout << "Introduceti optiunea: ";
        cin >> option;
        cout << endl;

        switch (option) {

            case 1:{

                int id;
                char* name = new char[11];
                int price;

                cout << "Introduceti id-ul produsului: ";
                cin >> id;
                cout << endl;

                cout << "Introduceti numele produsului [apa/suc/ciocolata/twix]: ";
                cin >> name;
                cout << endl;

                cout<< "Introduceti pretul produsului: ";
                cin >> price;
                cout << endl;

                ProductValidator validator(1);

                try{
                    validator.validate(price, id);
                }
                catch(InvalidPriceException* ex){
                    cout << ex->what() << endl;
                    break;
                }
                catch(NegativeIdException* ex){
                    cout << ex->what() << endl;
                    break;
                }
                catch(...){
                    cout << "Error!" << endl;
                    break;
                }

                try {
                    service.createElem(id, name, price);

                }catch (UniqueIDException* exception){
                    cout << exception->what() << endl;
                    break;
                }
                catch (...){
                    cout << "Exception!" << endl;
                }

                cout << "Adaugarea s-a efectuat cu succes!" << endl;

                delete[] name;

                break;
            }

            case 2:{

                int id;

                cout << "Introduceti id-ul produsului: ";
                cin >> id;
                cout << endl;

                Product readProduct;

                try {
                    readProduct = service.readElem(id);
                }
                catch (InvalidIDException* exception){
                    cout << exception->what() << endl;
                    break;
                }
                catch (...){
                    cout << "Exception!" << endl;
                }

                cout << readProduct;

                break;
            }

            case 3:{

                int id;
                char* name = new char[11];
                int price;

                cout << "Introduceti id-ul produsului: ";
                cin >> id;
                cout << endl;

                cout << "Introduceti numele produsului [apa/suc/ciocolata/twix]: ";
                cin >> name;
                cout << endl;

                cout<< "Introduceti pretul produsului: ";
                cin >> price;
                cout << endl;

                try {
                    service.updateElem(id, name, price);
                }
                catch (InvalidIDException* exception){
                    cout << exception->what() << endl;
                    break;
                }
                catch (...){
                    cout << "Exception!" << endl;
                }

                delete[] name;

                cout << "Modificarea s-a efectuat cu succes" << endl;

                break;
            }

            case 4:{

                int id;

                cout << "Introduceti id-ul" << endl;
                cin >> id;
                cout << endl;

                try {
                    service.deleteElem(id);
                }
                catch (InvalidIDException* exception){
                    cout << exception->what() << endl;
                    break;
                }
                catch (...){
                    cout << "Exception" << endl;
                }

                cout << "Stergerea s-a efectuat cu succes" << endl;

                break;
            }

            case 5: {

                int numberOfProducts = service.getFileRepo().getNumberOfEntities();

                Product* listOfProducts;

                listOfProducts = service.getFileRepo().getAll();

                for(int i = 0; i < numberOfProducts; i++)
                    cout << listOfProducts[i] << endl;

                break;
            }

            case 0: return 0;

            default: {
                cout << "Optiune invalida!" << endl;
                break;
            }

        }

    }

}

int UserInterface::runUserConsole() {
    while(true)
    {
        showUserConsole();

        int option;
        cout << "Introduceti optiunea: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1:{

                int numberOfProducts = service.getFileRepo().getNumberOfEntities();

                Product* listOfProducts;

                listOfProducts = service.getFileRepo().getAll();

                for(int i = 0; i < numberOfProducts; i++)
                    cout << listOfProducts[i] << endl;

                break;

            }

            case 2:{

                map<int, int> usersBanknotes;
                map<int, int>::iterator itr;

                usersBanknotes.insert(pair<int,int>(1, 0));
                usersBanknotes.insert(pair<int,int>(5, 0));
                usersBanknotes.insert(pair<int,int>(10, 0));
                usersBanknotes.insert(pair<int,int>(50, 0));
                usersBanknotes.insert(pair<int,int>(100, 0));
                usersBanknotes.insert(pair<int,int>(200, 0));
                usersBanknotes.insert(pair<int,int>(500, 0));


                int sumOfMoney = 0;
                int banknote;

                cout << "Introduceti o bancnota: ";
                cin >> banknote;
                sumOfMoney += banknote;
                cout << endl;

                for(itr = usersBanknotes.begin(); itr != usersBanknotes.end(); itr++)
                {
                    if(itr->first == banknote)
                    {
                        itr->second++;
                        break;
                    }
                }

                while(true)
                {
                    int decision;

                    cout << "Mai doriti sa introduceti o bancnota? [1-da/ 0-nu]: ";
                    cin >> decision;
                    cout << endl;

                    if(decision == 0)
                        break;
                    else if(decision == 1){
                        cout << "Introduceti bancnota: " << endl;
                        cin >> banknote;
                        cout << endl;

                        for(itr = usersBanknotes.begin(); itr != usersBanknotes.end(); itr++)
                        {
                            if(itr->first == banknote)
                            {
                                itr->second++;
                                sumOfMoney += banknote;
                                break;
                            }
                        }

                    }else{
                        cout << "Optiune invalida!" << endl;
                    }
                }

                int productId;

                cout << "Introduceti codul produsului: ";

                cin >> productId;
                cout << endl;

                Product product;

                try{
                    product = this->service.getProductByID(productId);
                }
                catch (InvalidIDException* exception){
                    cout << exception->what() << endl;
                    break;
                }
                catch (...){
                    cout << "Exception" << endl;
                }

                int change = sumOfMoney - product.getPrice();

                try {
                    if (!this->service.isChange(change)) {
                        cout << "Nu se poate elibera rest!" << endl;
                        cout << "S-au returnat " << sumOfMoney << "lei" << endl;
                        break;
                    } else {

                        this->service.buyProduct(usersBanknotes);
                        cout << "S-a returnat suma de " << change << "lei" << endl;
                    }
                }catch (NotEnoughMoneyException* exception){
                    cout << exception->what() << endl;
                    break;
                }
                catch (...){
                    cout << "Exception!" << endl;
                }

                break;
            }

            case 0:{
                return 0;
            }

            default:{
                cout << "Optiune invalida!" << endl;
                break;
            }

        }
    }
}

int UserInterface::runConsole() {

    while(true){

        cout << "1.Manager console" << endl;
        cout << "2.User console" << endl;
        cout << "0.Iesire din program" << endl;

        int option;
        cout << "Introduceti optiunea: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1:{
                runManagerConsole();
                break;
            }
            case 2:{

                runUserConsole();

                break;
            }
            case 0:{
                return 0;
            }
            default:{
                cout << "Optiune invalida!" << endl;
                break;
            }

        }

    }

}

