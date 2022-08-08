#include "Shop.h"
Stock Shop::magazyn;




void Shop::session() {
	
	Admin adminek;
	adminek.setLogin("admin");
	adminek.setPassword("admin123!");
	Client kliencik;

	kliencik.setLogin("1");
	kliencik.setPassword("1");

	Admin* ptr_adminek{ &adminek };
	Client* ptr_kliencik{ &kliencik };
	DisplayConsole konsola;

	int authorisation;
	int finish = 0;

	while (authorisation != 0) {
		konsola.printWelcomeScreen();
		authorisation = konsola.loginAndPassword(ptr_adminek, ptr_kliencik);
	}


	if (authorisation == 1) {
		while (finish != 3) {
			finish = konsola.userPanel(ptr_kliencik, stock);
		}
	}
	
	kliencik.koszyk.checkoutCart(ptr_kliencik);

}