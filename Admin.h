#pragma once
#include "User.h"
#include "Stock.h"
#include <map>

class Admin :
    public User
{
public:
    void Stock::addStock();
    void Stock::removeStock();
    void resetPassword(Client* client);
    virtual void login();
};
