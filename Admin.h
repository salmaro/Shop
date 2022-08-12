#pragma once
#include "Client.h"
#include "User.h"
#include "Stock.h"
#include <map>
#include <iostream>

class Admin :
    public User
{
public:

    void resetPassword(Client* client);
    void removeProductFromStock(Stock* stock);
    void addProductToStock();
};

