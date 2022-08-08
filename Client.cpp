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
	std::cin >> billingAdress.country;
	std::cout << "Please enter the city:" << std::endl;
	std::cin >> billingAdress.city;
	std::cout << "Please enter ythe zip Code:" << std::endl;
	std::cin >> billingAdress.zipCode;
	std::cout << "Please enter your address:" << std::endl;
	std::cin >> billingAdress.address;
	
}

void Client::setShippingAddress()
{
	std::cout << "Please enter your coutry:" << std::endl;
	std::cin >> shippingAdress.country;
	std::cout << "Please enter the city:" << std::endl;
	std::cin >> shippingAdress.city;
	std::cout << "Please enter the zip Code:" << std::endl;
	std::cin >> shippingAdress.zipCode;
	std::cout << "Please enter your address:" << std::endl;
	std::cin >> shippingAdress.address;
}
