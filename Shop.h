#pragma once
#include "DisplayConsole.h"
#include <string>


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
