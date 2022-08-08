#include "Client.h"

void Client::setBillingAddress()
{
	//ShippingAddress{"Poland","Warsaw","28608","Powstancow 10/2"};

	std::cout << "Please enter your coutry:" << std::endl;
	std::cin >> BillingAddress::country;
	std::cout << "Please enter your surname:" << std::endl;
	std::cin >> this->nazwisko;
	std::cout << "Please enter your email:" << std::endl;
	std::cin >> this->email;
	std::cout << "Please enter your phone number:" << std::endl;
	std::cin >> this->phoneNumber;
	
}

void Client::setShippingAddress()
{
	std::cout << "Please enter your name:" << std::endl;
	std::cin >> this->imie;
	std::cout << "Please enter your surname:" << std::endl;
	std::cin >> this->nazwisko;
	std::cout << "Please enter your email:" << std::endl;
	std::cin >> this->email;
	std::cout << "Please enter your phone number:" << std::endl;
	std::cin >> this->phoneNumber;
}
