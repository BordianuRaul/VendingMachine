
#include "Service/ProductService.h"
#include "UserInterface/UserInterface.h"
#include "Tests/Tests.h"

int main() {
    
    testAll();
    
    char* filename = new char[15];
    strcpy_s(filename, 15, "Repository.txt");
    
    FileRepository<Product> fileRepo(filename);
    
    map<int, int> banknotes;

    banknotes.insert(pair<int, int>(1, 10));
    banknotes.insert(pair<int, int>(5, 15));
    banknotes.insert(pair<int, int>(10, 10));
    banknotes.insert(pair<int, int>(50, 3));
    banknotes.insert(pair<int, int>(100, 1));
    banknotes.insert(pair<int, int>(200, 0));
    banknotes.insert(pair<int, int>(500, 0));

    ProductService service(fileRepo, banknotes);

    UserInterface console(service);

    console.runConsole();
    
    delete[] filename;

    return 0;
}
