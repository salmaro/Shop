#include "Admin.h"


void Admin::addStock(Stock*)
{

}

void Admin::removeStock(Stock*)
{
}

void Admin::resetPassword(Client* client)
{
	std::string clientPassword = client->getPassword();
	std::string newPassword;
	std::cout << "Your password has been reset, now please enter a new password: \n" << std::endl;
	std::cin >> newPassword;
	client->setPassword(newPassword);
	std::cout << "Your password has been changed." << std::endl;
}
