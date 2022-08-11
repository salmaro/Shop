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
	std::cin >> billingAddress.country;
	std::cout << "Please enter the city:" << std::endl;
	std::cin >> billingAddress.city;
	std::cout << "Please enter the zip Code:" << std::endl;
	std::cin >> billingAddress.zipCode;
	std::cout << "Please enter your address:" << std::endl;
	std::cin >> billingAddress.address;
	
}

void Client::setShippingAddress(int i)
{
	if (i == 1) {
		
		 shippingAddress.country = billingAddress.country;
		 shippingAddress.city = billingAddress.city;
		 shippingAddress.zipCode = billingAddress.zipCode;
		 shippingAddress.address = billingAddress.address;
	}
	else {
		std::cout << "Please enter your coutry:" << std::endl;
		std::cin >> shippingAddress.country;
		std::cout << "Please enter the city:" << std::endl;
		std::cin >> shippingAddress.city;
		std::cout << "Please enter the zip Code:" << std::endl;
		std::cin >> shippingAddress.zipCode;
		std::cout << "Please enter your address:" << std::endl;
		std::cin >> shippingAddress.address;
	}
}

struct Client ::BillingAddress Client::getBillingAddress()
{
	return billingAddress;
}

void Client::displayAddress()
{
	std::cout << "\033[1;33mShipping Address: \n"
		<< shippingAddress.address << std::endl
		<< shippingAddress.city << std::endl
		<< shippingAddress.country << std::endl
		<< shippingAddress.zipCode << std::endl;
	std::cout << " \033[0m"<< std::endl;

	std::cout << std::endl;
	std::cout << "Billing Address: \n" 
		<< billingAddress.address << std::endl
		<< billingAddress.city << std::endl
		<< billingAddress.country << std::endl
		<< billingAddress.zipCode << std::endl;
	std::cout << std::endl;
}
