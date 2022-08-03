#pragma once
#include "User.h"
#include "Cart.h"
#include<string>

class Client :
    public User
{ 
public:
    std::string imie;
    std::string nazwisko;
    std::string email;
    std::string phoneNumber;

    struct BillingAddress 
    {
        std::string country;
        std::string city;
        std::string zipCode;
        std::string address;

    };
    struct ShippingAddress
    {
        std::string country;
        std::string city;
        std::string zipCode;
        std::string address;

    };
    Cart koszyk;
};
