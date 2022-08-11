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
    bool displayCart(Stock* stock); // zmienione na bool bo - jezeli true idziemy do checkout jezeli false to idziemy na main menu
    std::map<Product*, int> getCurrentCart();
    void cartOptions(Stock* stock);
    void editCartOptions(Stock* stock);
    void printCart();
    int checkoutCart(Stock* stock);
    int validationInput(int start, int stop);
};


