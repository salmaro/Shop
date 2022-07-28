#pragma once
#include "User.h"
#include<string>

class Client :
    public User
{
private:
    std::string deliveryAddress;
};
