#pragma once
#include "DisplayConsole.h"


class Shop
{
protected:
	
public:
	static Stock magazyn;
	Stock* stock = &magazyn;
	void session();
	void payment();
};
