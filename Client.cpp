#include "Client.h"

void Client::setPersonalData() {

	std::cout << "\n\t----- PERSONAL DATA -----\n";
	std::cout << "\tPlease enter your name >>  ";
	std::cin >> this->name;
	std::cout << "\tPlease enter your surname >>  ";
	std::cin >> this->surname;
	std::cout << "\tPlease enter your email >>  ";
	std::cin >> this->email;
	std::cout << "\tPlease enter your phone number >>  ";
	std::cin >> this->phoneNumber;
}

void Client::setBillingAddress() {
	//ShippingAddress{"Poland","Warsaw","28608","Powstancow 10/2"};
	std::cout << "\n\t----- BILLING ADDRESS -----\n";
	std::cout << "\tPlease enter your coutry >>  ";
	std::cin >> billingAddress.country;
	std::cout << "\tPlease enter the city >>  ";
	std::cin >> billingAddress.city;
	std::cout << "\tPlease enter the zip Code >>  ";
	std::cin >> billingAddress.zipCode;
	std::cout << "\tPlease enter your address >>  ";
	std::cin >> billingAddress.address;
	
}

void Client::setShippingAddress(int i) {

	if (i == 1) {
		 shippingAddress.country = billingAddress.country;
		 shippingAddress.city = billingAddress.city;
		 shippingAddress.zipCode = billingAddress.zipCode;
		 shippingAddress.address = billingAddress.address;
	}
	else {
		std::cout << "\n\t----- SHIPPING ADDRESS -----\n";
		std::cout << "\tPlease enter your coutry >>  ";
		std::cin >> shippingAddress.country;
		std::cout << "\tPlease enter the city >>  ";
		std::cin >> shippingAddress.city;
		std::cout << "\tPlease enter the zip Code >>  ";
		std::cin >> shippingAddress.zipCode;
		std::cout << "\tPlease enter your address >>  ";
		std::cin >> shippingAddress.address;
	}
}

struct Client ::BillingAddress Client::getBillingAddress() {

	return billingAddress;
}

void Client::displayAddress() {

	std::cout << "\t\033[1;33mShipping Address: \n"
		<< "\t"<<shippingAddress.address << std::endl
		<< "\t" << shippingAddress.city << std::endl
		<< "\t" << shippingAddress.country << std::endl
		<< "\t" << shippingAddress.zipCode << std::endl;
	std::cout << " \033[0m"<< std::endl;

	std::cout << std::endl;
	std::cout << "\tBilling Address: \n" 
		<< "\t" << billingAddress.address << std::endl
		<< "\t" << billingAddress.city << std::endl
		<< "\t" << billingAddress.country << std::endl
		<< "\t" << billingAddress.zipCode << std::endl;
	std::cout << std::endl;
}