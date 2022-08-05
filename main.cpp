#include <iostream>
#include "admin.h"
#include "client.h"
#include "displayConsole.h"
#include <map>
#include "product.h"
#include "stock.h"
#include "user.h"
#include "userInterface.h"





int main() {
	Product nowy;
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