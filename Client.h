#pragma once
#include "user.h"
#include "cart.h"
#include<string>

class Client :
    public User
{ 
private:
    std::string imie;
    std::string nazwisko;
    std::string email;
    std::string phoneNumber;

   static struct BillingAddress 
    {
        static std::string country;
        static std::string city;
        static std::string zipCode;
        static std::string address;

    };
    static struct ShippingAddress
    {
        static std::string country;
        static std::string city;
        static std::string zipCode;
        static std::string address;

    };
    Cart koszyk;

    void setBillingAddress();
    void setShippingAddress();
};
