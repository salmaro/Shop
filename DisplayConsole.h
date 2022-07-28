#pragma once
#include <iostream>
#include "UserInterface.h"
#include "Admin.h"
#include "Client.h"
class DisplayConsole :
    public UserInterface
{


public:

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