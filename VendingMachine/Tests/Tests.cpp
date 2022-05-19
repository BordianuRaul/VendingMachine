//
// Created by Raul on 5/10/2022.
//


#include "../Headers/Product.h"
#include "../Headers/ProductValidator.h"
#include "../Repository/Repository.h"
#include "../Service/ProductService.h"
#include <cstring>
#include <cassert>
#include <map>

void testProduct()
{
    Product product;
}

void testProductConstructor(){

    char* name = new char[6];
    strcpy_s(name, 6, "cioco");

    Product product(1, name, 20);

    delete[] name;
}

void testGetId(){

    char* name = new char[6];
    strcpy_s(name, 6, "cioco");

    Product product(1, name, 20);

    product.setId(2);

    assert(product.getId() == 2);

    delete[] name;

}

void testRepo(){

    Repository<Product> repo;

}

void testRepoConstructor(){

    auto* products = new Product[1];

    Repository<Product> repo(products, 1, 0);

    delete[] products;
}

void testAssigmentRepo(){

    auto* name = new char[6];
    strcpy_s(name, 6, "cioco");
    Product product(1, name ,100);
    auto* entities = new Product[1];
    entities[0] = product;
    Repository<Product> repo(entities, 1, 1);
    Repository<Product> testRepo;
    testRepo = repo;
    assert(testRepo == repo);

    delete[] entities;
    delete[] name;

}

void testGetCapacity(){

    char* name = new char[6];
    strcpy_s(name, 6, "cioco");
    Product product(1, name, 12);

    auto* entities = new Product[1];
    entities[0] = product;
    Repository<Product> repo(entities, 1, 1);

    assert(repo.getCapacity() == 1);

    delete[] entities;
    delete[] name;

}

void testGetNumberOfEntities(){

    char* name = new char[6];
    strcpy_s(name, 6, "cioco");
    Product product(1, name, 20);
    auto* entities = new Product[1];
    entities[0] = product;
    Repository<Product> repo(entities, 1, 1);

    assert(repo.getNumberOfEntities() == 1);

    delete[] entities;
    delete[] name;

}

void testAddRepository(){

    auto *name = new char[6];
    strcpy_s(name, 6, "cioco");
    auto *entities = new Product[1];
    Repository<Product> repo(entities, 1, 0);

    Product entity(1, name, 12);

    repo.addElem(entity);
    repo.addElem(entity);
    assert(repo.getNumberOfEntities() == 2);

    delete[] entities;
    delete[] name;
}

void testGetAllRepository(){

    auto *name = new char[6];
    strcpy_s(name, 6, "cioco");
    auto *entities = new Product[1];
    Repository<Product> repo(entities, 1, 0);

    Product entity(1, name, 12);

    repo.addElem(entity);

    entity.setPrice(7);
    repo.addElem(entity);

    strcpy_s(name, 4, "suc");
    entity.setName(name);

    repo.addElem(entity);

    Product* all_entities;

    all_entities = repo.getAll();

    strcpy_s(name, 6, "cioco");

    Product compare_entity(1, name, 12);

    assert(all_entities[0] == compare_entity);

    compare_entity.setPrice(7);
    assert(all_entities[1] == compare_entity);

    strcpy_s(name, 4, "suc");
    compare_entity.setName(name);
    assert(all_entities[2] == compare_entity);

    delete[] entities;
    delete[] name;

}

void testProductService(){

    ProductService jukebox;

}

void testProductServiceConstructor(){


    char* fileName = new char[9];
    strcpy_s(fileName, 9, "testRepo");
    FileRepository<Product> repo(fileName);

    char* name = new char[6];
    strcpy_s(name, 6,"cioco");
    Product addProduct(1, name, 100);

    repo.addElem(addProduct);

    map<int, int> banknotes;

    banknotes.insert(pair<int, int>(1, 12));

    ProductService jukebox(repo, banknotes);

    delete[] name;
    delete[] fileName;

}

void testCreateProductService(){

    char* filename = new char[29];

    strcpy_s(filename, 29,"testCreateProductService.txt");

    std::ofstream ofs;
    ofs.open("testCreateProductService.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    FileRepository<Product> fileRepo(filename);

    map<int, int> banknotes;

    banknotes.insert(pair<int, int>(10, 5));

    ProductService jukebox(fileRepo,banknotes);

    char* name = new char[6];
    strcpy_s(name, 6,"cioco");

    jukebox.createElem(1, name, 120);
    jukebox.createElem(2, name, 140);

    assert(jukebox.getFileRepo().getNumberOfEntities() == 2);

    delete[] name;
    delete[] filename;
}

void testReadProductService()
{
    char* filename = new char[27];

    strcpy_s(filename, 27,"testReadProductService.txt");

    std::ofstream ofs;
    ofs.open("testReadProductService.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    FileRepository<Product> fileRepo(filename);

    map<int, int> banknotes;

    banknotes.insert(pair<int, int>(10, 5));

    ProductService jukebox(fileRepo,banknotes);

    char* name = new char[6];
    strcpy_s(name, 6,"cioco");

    jukebox.createElem(1, name, 120);
    jukebox.createElem(12, name, 40);
    jukebox.createElem(25, name, 20);

    Product compareProduct(1, name, 120);

    assert(jukebox.readElem(1) == compareProduct);
    delete[] name;
}

void testUpdateProductService(){

    char* filename = new char[29];

    strcpy_s(filename, 29,"testUpdateProductService.txt");

    std::ofstream ofs;
    ofs.open("testUpdateProductService.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    FileRepository<Product> fileRepo(filename);

    map<int, int> banknotes;

    banknotes.insert(pair<int, int>(10, 5));

    ProductService jukebox(fileRepo,banknotes);

    char* name = new char[6];
    strcpy_s(name, 6,"cioco");

    jukebox.createElem(1, name, 120);
    jukebox.createElem(12, name, 40);
    jukebox.createElem(25, name, 20);

    Product compareProduct(1, name, 200);

    jukebox.updateElem(1, name, 200);
    assert(jukebox.readElem(1) == compareProduct);
    delete[] name;

}

void testDeleteProductService(){

    char* filename = new char[29];

    strcpy_s(filename, 29,"testDeleteProductService.txt");

    std::ofstream ofs;
    ofs.open("testDeleteProductService.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    FileRepository<Product> fileRepo(filename);

    map<int, int> banknotes;

    banknotes.insert(pair<int, int>(10, 5));

    ProductService jukebox(fileRepo,banknotes);

    char* name = new char[6];
    strcpy_s(name, 6,"cioco");

    jukebox.createElem(1, name, 120);
    jukebox.createElem(12, name, 40);
    jukebox.createElem(25, name, 20);

    jukebox.deleteElem(1);

    assert(jukebox.getFileRepo().getNumberOfEntities() == 2);
    delete[] name;

}

void testEqualOperatorProductService(){


    ProductService service;

    FileRepository<Product> repo;
    map<int, int> banknotes;
    banknotes.insert(pair<int, int>(10, 2));
    ProductService newService(repo,banknotes);

    service = newService;

    assert(newService.getBanknotes() == service.getBanknotes());

}

void testAddRepoFile()
{
    auto *name = new char[6];
    strcpy_s(name, 6, "cioco");

    auto *fileName = new char[20];
    strcpy_s(fileName, 20, "testAddRepoFile.txt");

    std::ofstream ofs;
    ofs.open("testAddRepoFile.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    FileRepository<Product> fileRepo(fileName);

    Product entity(1, name, 12);

    fileRepo.addElemFile(entity);
    fileRepo.addElemFile(entity);

    assert(fileRepo.getNumberOfEntities() == 2);

    delete[] name;
    delete[] fileName;
}

void testDeleteRepoFile()
{
    auto *name = new char[6];
    strcpy_s(name, 6, "cioco");

    auto *fileName = new char[23];
    strcpy_s(fileName, 9, "testDeleteRepoFile.txt");

    std::ofstream ofs;
    ofs.open("testDeleteRepoFile.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    FileRepository<Product> fileRepo(fileName);

    Product entity(1, name, 12);

    fileRepo.addElemFile(entity);

    entity.setPrice(15);
    fileRepo.addElemFile(entity);

    fileRepo.deleteElemFile(entity);

    assert(fileRepo.getNumberOfEntities() == 1);

    delete[] name;
    delete[] fileName;
}

void testTotalSum(){

    ProductService jukebox;

    char* name = new char[6];
    strcpy_s(name, 6,"cioco");

    map<int, int> banknotes;

    banknotes.insert(pair<int, int>(1, 0));
    banknotes.insert(pair<int, int>(5, 0));
    banknotes.insert(pair<int, int>(10, 0));
    banknotes.insert(pair<int, int>(50, 3));
    banknotes.insert(pair<int, int>(100, 2));
    banknotes.insert(pair<int, int>(200, 0));
    banknotes.insert(pair<int, int>(500, 0));

    jukebox.setBanknotes(banknotes);

    int sum;

    sum = jukebox.totalSum();

    assert(sum == 350);

    delete[] name;

}

void testBuyProduct()
{
    char* filename = new char[19];

    strcpy_s(filename, 19,"testBuyProduct.txt");

    std::ofstream ofs;
    ofs.open("testBuyProduct.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    FileRepository<Product> fileRepo(filename);

    map<int, int> banknotes;

    banknotes.insert(pair<int, int>(10, 5));

    ProductService jukebox(fileRepo,banknotes);

    char* name = new char[6];
    strcpy_s(name, 6,"cioco");

    jukebox.createElem(1, name, 100);

    map<int, int> moneyForProduct;
    moneyForProduct.insert(pair<int, int>(10, 10));

    jukebox.buyProduct(moneyForProduct);

    map<int, int>compareBanknotes;
    compareBanknotes.insert(pair<int, int>(10, 15));

    assert(jukebox.getBanknotes() == compareBanknotes);

    delete[] name;
}

void testIsChange(){

    char* filename = new char[17];

    strcpy_s(filename, 17,"testIsChange.txt");

    std::ofstream ofs;
    ofs.open("testIsChange.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    FileRepository<Product> fileRepo(filename);

    map<int, int> banknotes;

    banknotes.insert(pair<int, int>(10, 5));

    ProductService jukebox(fileRepo,banknotes);

    assert(jukebox.isChange(20) == true);

}

void testGiveChange(){
    char* filename = new char[19];

    strcpy_s(filename, 19,"testGiveChange.txt");

    std::ofstream ofs;
    ofs.open("testGiveChange.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    FileRepository<Product> fileRepo(filename);

    map<int, int> banknotes;

    banknotes.insert(pair<int, int>(10, 5));

    ProductService jukebox(fileRepo,banknotes);

    map<int, int> compareChange;

    compareChange.insert(pair<int,int>(10, 2));

    assert(jukebox.giveChange(20) == compareChange);
}

void testValidator(){

    ProductValidator validator(1);

    try{
        validator.validate(0, 2);
    }catch (InvalidPriceException* ex){
        assert(true);
        return;
    }catch (NegativeIdException* ex){
        assert(true);
        return;
    }catch(...){
        assert(false);
    }
    assert(false);

}

void testAll(){
    testProduct();
    testProductConstructor();
    testGetId();
    testRepo();
    testRepoConstructor();
    testAssigmentRepo();
    testGetCapacity();
    testGetNumberOfEntities();
    testAddRepository();
    testGetAllRepository();
    testProductService();
    testProductServiceConstructor();
    testCreateProductService();
    testReadProductService();
    testUpdateProductService();
    testDeleteProductService();
    testEqualOperatorProductService();
    testAddRepoFile();
    testDeleteRepoFile();
    testTotalSum();
    testBuyProduct();
    testIsChange();
    testGiveChange();
    testValidator();
}

