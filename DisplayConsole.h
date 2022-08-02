#pragma once
#include <iostream>
#include "UserInterface.h"
#include "Admin.h"
#include "Client.h"
#include <iomanip>


class DisplayConsole :
    public UserInterface
{
private: 

    Stock magazyn;

public:
    //void sortProductByName(Stock* storage, int sortDirection/*wskaznik const na stock od andrzeja + opcja czy od a do z czy z do a*/);
    //void sortProductByPrice(Stock* storage, int sortDirection/*wskaznik const  na stock od andrzeja + opcja czy rosnaco/ malejaco */);
    //void filtrBySupplier(Stock* storage/*wskaznik const  na stock od andrzeja + nazwa dostawcy */);
    //void filtrByCategory(Stock* storage);
    //void chooseTypeOfSorting();
    //void chooseTypeOfFiltering();

    void printList();
=======
>>>>>>> 35b36c904bd8197dee37563a89751e2be58487d6
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
    void printCartContents();
    void sortPriceDescending();

};
