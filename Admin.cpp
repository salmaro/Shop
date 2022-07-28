#include "Admin.h"
#include "Client.h"
#include <iostream>

void Admin::resetPassword(Client* client)
{
	std::string clientPassword = client->getPassword();
	std::string newPassword;
	std::cout << "Your password has been reset, now please enter a new password: \n" << std::endl;
	std::cin >> newPassword;
	client->setPassword(newPassword);
	std::cout << "Your password has been changed." << std::endl;
}

void Admin::login()
{
	std::string userInput;

	std::cout << "Please enter your password: " << std::endl;
	std::cin >> userInput;

	while (userInput != password) {
		std::cout << "Wrong password! Try again.";
	}
}