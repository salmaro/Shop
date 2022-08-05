#pragma once
#include <iostream>
#include "userInterface.h"
#include "admin.h"
#include "client.h"
#include <iomanip>
#include <string>
#include "stock.h"
#include "shop.h"


class DisplayConsole :
    public Client, Shop
{
private: 

 
public:
    //void sortProductByName(Stock* storage, int sortDirection/*wskaznik const na stock od andrzeja + opcja czy od a do z czy z do a*/);
    //void sortProductByPrice(Stock* storage, int sortDirection/*wskaznik const  na stock od andrzeja + opcja czy rosnaco/ malejaco */);
    //void filtrBySupplier(Stock* storage/*wskaznik const  na stock od andrzeja + nazwa dostawcy */);
    //void filtrByCategory(Stock* storage);
    //void chooseTypeOfSorting();
    //void chooseTypeOfFiltering();
   
    void printList();
    void printWelcomeScreen(Admin*, Client*);
    void loginAndPassword(Admin* admin, Client* client);
    void adminPanel();
    void userPanel();
    void printTypeOfSorting();
    void printTypeOfFiltering();
    void sortPriceAscending();
    void filterByCategory();
    void filterBySupplier();
    int getCategory();
    int getSupplier();
    void sortInReverseAlphabeticalOrder();
    void sortInAlphabeticalOrder();
    //void printCartContents();
    void sortPriceDescending();

};
