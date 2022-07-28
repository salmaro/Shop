#pragma once
#include <iostream>
class DisplayConsole :
    public UserInterface
{


public:

    void printWelcomeScreen();
    void loginAndPassword(Admin* admin, Client* client);
    void adminPanel();
    void userPanel();
    void printTypeOfSorting(std::map <*item, int> storage);
    void printTypeOfFiltering(std::map <*item, int> stock);
    void sortPriceAscending(std::map<*item, int> storage);


    //TODO 
    void printCartContents();
    void sortPriceDescending(std::map <*item, int> storage);
    void sortPriceAscending(std::map <*item, int> storage);
    void sortInAlphabeticalOrder(std::map <*item, int> storage);
    void sortInReverseAlphabeticalOrder(std::map <*item, int> storage);
    void filterBySupplier(std::map <*item, int> strage);
    void filterByCategory(std::map <*item, int> storage);
};
