#pragma once
#include "User.h"
#include<string>

class Client :
    public User
{
    std::string deliveryAddress;

public:
    Client(std::string name, std::string password);
    std::string getPassword();
    void setPassword(std::string password);
    virtual void login();
};
