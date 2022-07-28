#include "User.h"

void User::setPassword(std::string inputPassword)
{
	password = inputPassword;
}

void User::setLogin(std::string inputName)
{
	name = inputName;
}

std::string User::getLogin()
{
	return name;
}

std::string User::getPassword()
{
	return password;
}