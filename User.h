#pragma once
#include <string>

class User
{
public:

	void setPassword(std::string);
	void setLogin(std::string);
	std::string getLogin();
	std::string getPassword();

protected:
	std::string name;
	std::string password;
};
