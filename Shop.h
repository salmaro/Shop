#pragma once
#include "Admin.h"
#include "Cart.h"
#include "Client.h"
#include "DisplayConsole.h"
#include "Product.h"
#include "Stock.h"
#include "User.h"
#include "UserInterface.h"

class Shop
{
protected:
	
public:
	static Stock magazyn;
	Stock* stock = &magazyn;
	void session();

	

	
};

