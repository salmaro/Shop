#pragma once
#include "User.h"
#include "stock.h"
#include <map>

class Admin :
    public User
{
public:
    void stock::stock addStock();
    void stock::removeStock();
    void resetPassword(Client* client);
    virtual void login();
};
