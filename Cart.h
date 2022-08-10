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
    void removeProduct(Stock* stock);
    void changeQuantity(Stock * stock);
    void displayCart(Stock* stock);
    std::map<Product*, int> getCurrentCart();
    void cartOptions(Stock* stock);
    void editCartOptions(Stock* stock);
    void printCart();
    int checkoutCart(Stock* stock);
    int validationInput(int start, int stop);
};


