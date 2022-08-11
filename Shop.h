#pragma once
#include "DisplayConsole.h"
#include <string>
#include <fstream>


class Shop
{
protected:
	
public:
	static Stock magazyn;
	Stock* stock = &magazyn;
	int session();
	void payment(Client *klient);
	void summaryOfOrder(Client* client);
};
