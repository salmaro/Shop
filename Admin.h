#pragma once
#include "Client.h"
#include "User.h"
#include "stock.h"
#include <map>
#include <iostream>

class Admin :
    public User
{
public:

    void addStock(Stock*);  // TODO dopisac userInterface do Admina
    void removeStock(Stock*);
    void resetPassword(Client* client);
};
