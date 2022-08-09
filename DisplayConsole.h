#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Stock.h"
#include "Client.h"
#include "Admin.h"

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
    void filterByCategory(Stock* stock, int category);
    void filterBySupplier(Stock* stock, int supplier);
    int getCategory(Stock* stock);
    int getSupplier(Stock* stock);
    void sortInOrder(Stock* stock, int direct);
    void sortPriceDescending(Stock* stock);
    int orderConfirmation();

};
