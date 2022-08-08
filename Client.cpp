#include "Client.h"

void Client::setPersonalData()
{
	std::cout << "Please enter your name:" << std::endl;
	std::cin >> this->name;
	std::cout << "Please enter your surname:" << std::endl;
	std::cin >> this->surname;
	std::cout << "Please enter your email:" << std::endl;
	std::cin >> this->email;
	std::cout << "Please enter your phone number:" << std::endl;
	std::cin >> this->phoneNumber;
}

void Client::setBillingAddress()
{
	//ShippingAddress{"Poland","Warsaw","28608","Powstancow 10/2"};

	std::cout << "Please enter your coutry:" << std::endl;
	std::cin >> BillingAddress::country;
	std::cout << "Please enter your surname:" << std::endl;
	std::cin >> BillingAddress::city;
	std::cout << "Please enter your email:" << std::endl;
	std::cin >> BillingAddress::zipCode;
	std::cout << "Please enter your phone number:" << std::endl;
	std::cin >> BillingAddress::address;
	
}

void Client::setShippingAddress()
{
	std::cout << "Please enter your coutry:" << std::endl;
	std::cin >> ShippingAddress::country;
	std::cout << "Please enter your surname:" << std::endl;
	std::cin >> ShippingAddress::city;
	std::cout << "Please enter your email:" << std::endl;
	std::cin >> ShippingAddress::zipCode;
	std::cout << "Please enter your phone number:" << std::endl;
	std::cin >> ShippingAddress::address;
}
