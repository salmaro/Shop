#include "Client.h"
#include <string>
#include <iostream>

Client::Client(std::string name, std::string password)
{
	this->name = name;
	this->password = password;
}

std::string Client::getPassword()
{
	return password;
}

void Client::setPassword(std::string password)
{
	this->password = password;
}

void Client::login()
{
	std::string userInput;
	std::cout << "Please enter your password: " << std::endl;
	std::cin >> userInput;

	while (userInput != password) {
		std::cout << "Wrong password! Try again.";
	}
}