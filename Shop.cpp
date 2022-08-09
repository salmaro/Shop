#include "Shop.h"

Stock Shop::magazyn;

int Shop::session() {
	
	Admin adminek;
	adminek.setLogin("admin");
	adminek.setPassword("admin123!");
	Client kliencik;

	kliencik.setLogin("1");
	kliencik.setPassword("1");

	Admin* ptr_adminek{ &adminek };
	Client* ptr_kliencik{ &kliencik };
	DisplayConsole konsola;

	int authorisation = 0;
	int finish = 0;

	while (authorisation != 1) {
		konsola.printWelcomeScreen();
		authorisation = konsola.loginAndPassword(ptr_adminek, ptr_kliencik);
	}


	if (authorisation == 1) {
		while (finish != 3) {
			shopping:
			finish = konsola.userPanel(ptr_kliencik, stock);
		}
	}
	
	if (kliencik.koszyk.checkoutCart() == 69) {
		kliencik.setPersonalData();
		kliencik.setBillingAddress();
		int input{};
		std::cout << "\nWhether Billing Adress is the same as Shipping Adress? " << std::endl;
		std::cout << "1 - YES.\n"
			<< "2 - NO.\n>> ";

		std::cin >> input;
		 
		kliencik.setShippingAddress(input);
		kliencik.displayAddress();
		payment(ptr_kliencik);

		system("pause");
		return 0;
	}
	else {
		goto shopping;
	}
	
}

void Shop::payment(Client* client_ptr) {
	int input;
	std::cout << "Your total price is: ";
	std::cout << client_ptr->koszyk.getTotalPrice();
	std::cout << "\nPlease choose payment method:\n";
	std::cout << "1 - PayPal\n";
	std::cout << "2 - Credit Card\n";
	std::cout << ">> ";
	std::cin >> input;

	std::cout << "\nYour order is complete. Please wait for an email with payment confirmation.\n";
}