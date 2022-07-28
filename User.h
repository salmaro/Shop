#pragma once
#include <string>

class User
{
public:
	virtual void login() = 0;

protected:
	std::string name;
	std::string password;
};
