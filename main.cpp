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
	//Product nowy;
	Admin adminek;
	adminek.setLogin("admin");
	adminek.setPassword("admin123!");
	Client kliencik;
	kliencik.setLogin("1");
	kliencik.setPassword("1");

	Admin* ptr_adminek{ &adminek };
	Client* ptr_kliencik{ &kliencik };
	DisplayConsole konsola;
	konsola.printWelcomeScreen(ptr_adminek, ptr_kliencik);





	return 0;
}