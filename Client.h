#pragma once
#include "User.h"
#include "Cart.h"
#include<string>

class Client :
    public User
{ 
private:
    std::string name;
    std::string surname;
    std::string email;
    std::string phoneNumber;

    struct BillingAddress 
    {
         std::string country;
         std::string city;
         std::string zipCode;
         std::string address;
    };
    BillingAddress billingAdress;

     struct ShippingAddress
    {
         std::string country;
         std::string city;
         std::string zipCode;
         std::string address;
    };
     ShippingAddress shippingAdress;
public:
    Cart koszyk;
    void setPersonalData();
    void setBillingAddress();
    void setShippingAddress();
};


