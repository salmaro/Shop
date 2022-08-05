#pragma once
#include "stock.h"
#include <iomanip>
#include "DisplayConsole.h"
//#include "Client.h"

class Cart :
    public DisplayConsole
{
private:
    std::map<Product*, int> currentCart;
    float totalPrice;

public:

    float getTotalPrice();
    void addProduct(int productID);
    void removeProduct();
    void changeQuantity();
    void displayCart();
    std::map<Product*, int> getCurrentCart();
    void cartOptions();
    void editCartOptions();
    void printCart();
    void checkoutCart();
    void payment();

 
};

