#pragma once
#include <iomanip>
#include <map>
#include "Stock.h"




class Cart
{
private:
    std::map<Product*, int> currentCart;
    float totalPrice;
public:
    float getTotalPrice();
    void addProduct(int productID, Stock* stock);
    void removeProduct();
    void changeQuantity(Product* chosenProduct, Stock * stock);
    void displayCart();
    std::map<Product*, int> getCurrentCart();
    void cartOptions();
    void editCartOptions();
    void printCart();
    int checkoutCart();
};


