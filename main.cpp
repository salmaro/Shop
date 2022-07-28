
#pragma once
#include <iostream>
#include "Admin.h"
#include "Client.h"
#include "DisplayConsole.h"
#include <map>
#include "Product.h"
#include "stock.h"
#include "User.h"
#include "UserInterface.h"


int main() {
	Admin adminek;
	adminek.setLogin("admin");
	adminek.setPassword("admin123!");
	Client kliencik;
	kliencik.setLogin("janusz");
	kliencik.setPassword("januszigrazynka");

	Admin* ptr_adminek{ &adminek };
	Client* ptr_kliencik{ &kliencik };

	return 0;
}