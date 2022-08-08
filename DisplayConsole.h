#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Shop.h"


class DisplayConsole{
public:
    //void sortProductByName(Stock* storage, int sortDirection/*wskaznik const na stock od andrzeja + opcja czy od a do z czy z do a*/);
    //void sortProductByPrice(Stock* storage, int sortDirection/*wskaznik const  na stock od andrzeja + opcja czy rosnaco/ malejaco */);
    //void filtrBySupplier(Stock* storage/*wskaznik const  na stock od andrzeja + nazwa dostawcy */);
    //void filtrByCategory(Stock* storage);
    //void chooseTypeOfSorting();
    //void chooseTypeOfFiltering();
   
    void printList(Stock* stock);
    void printWelcomeScreen();
    int loginAndPassword(Admin* admin, Client* client);
    void adminPanel();
    int userPanel(Client* client, Stock *stock);
    void printTypeOfSorting(Stock* stock);
    void printTypeOfFiltering(Stock * stock);
    void sortPriceAscending(Stock* stock);
    void filterByCategory(Stock* stock);
    void filterBySupplier(Stock* stock);
    int getCategory();
    int getSupplier();
    void sortInReverseAlphabeticalOrder(Stock* stock);
    void sortInAlphabeticalOrder(Stock* stock);
    //void printCartContents();
    void sortPriceDescending(Stock* stock);

};
