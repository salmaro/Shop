#pragma once
#include <iostream>
#include "UserInterface.h"
#include "Admin.h"
#include "Client.h"


class DisplayConsole :
    public UserInterface
{

public:
    //void sortProductByName(Stock* storage, int sortDirection/*wskaznik const na stock od andrzeja + opcja czy od a do z czy z do a*/);
    //void sortProductByPrice(Stock* storage, int sortDirection/*wskaznik const  na stock od andrzeja + opcja czy rosnaco/ malejaco */);
    //void filtrBySupplier(Stock* storage/*wskaznik const  na stock od andrzeja + nazwa dostawcy */);
    //void filtrByCategory(Stock* storage);
    //void chooseTypeOfSorting();
    //void chooseTypeOfFiltering();

<<<<<<< HEAD
    void printList(std::map <Product*, int> storage);
=======
>>>>>>> 35b36c904bd8197dee37563a89751e2be58487d6
    void printWelcomeScreen(Admin*, Client*);
    void loginAndPassword(Admin* admin, Client* client);
    void adminPanel();
    void userPanel();
    void printTypeOfSorting(std::map <Product*, int> storage);
    void printTypeOfFiltering(std::map <Product*, int> storage);
    void sortPriceAscending(std::map <Product*, int> storage);
    //void filterByCategory(std::map <Product*, int> storage);
    //void filterBySupplier(std::map <Product*, int> storage);
    //void sortInReverseAlphabeticalOrder(std::map <Product*, int> storage);
   // void sortInAlphabeticalOrder(std::map <Product*, int> storage);
   // void printCartContents();
   // void sortPriceDescending(std::map <Product*, int> storage);

};
