
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
<<<<<<< HEAD
	//Stock magazyn;
	DisplayConsole dupa;
	dupa.printWelcomeScreen(ptr_adminek, ptr_kliencik);
	//dupa.printList(magazyn.getStorage());
=======
>>>>>>> 35b36c904bd8197dee37563a89751e2be58487d6

	return 0;
}