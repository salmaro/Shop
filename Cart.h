#pragma once
#include "stock.h"
#include <iomanip>
#include "Shop.h"
//#include "Client.h"

class Cart :
    public Shop
{
private:
    std::map<Product*, int> currentCart;
    float totalPrice;

public:

    float getTotalPrice();
    void addProduct(int productID);
    void removeProduct();
    void changeQuantity(Product* chosenProduct);
    void displayCart();
    std::map<Product*, int> getCurrentCart();
    void cartOptions();
    void editCartOptions();
    void printCart();
    void checkoutCart();
    void payment();

 
};

