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
		system("cls");
		konsola.printWelcomeScreen();
		authorisation = konsola.loginAndPassword(ptr_adminek, ptr_kliencik);
		Sleep(1000);
		system("cls");
	}

	if (authorisation == 1) {
		while (finish != 3) {
			shopping:
			finish = konsola.userPanel(ptr_kliencik, stock);
		}
	}
	
	if (kliencik.koszyk.checkoutCart(stock) == 1) {
		kliencik.setPersonalData();
		kliencik.setBillingAddress();
		int input{};
		std::cout << "\n\tWhether Billing Adress is the same as Shipping Adress? " << std::endl;
		std::cout << "1 - YES.\n"
			<< "2 - NO.\n>> ";

		std::cin >> input;
		 
		kliencik.setShippingAddress(input);
		kliencik.displayAddress();
		payment(ptr_kliencik);
		summaryOfOrder(ptr_kliencik);

		system("pause");
		return 0;
	}
	else {
		goto shopping;
	}
	
}

void Shop::payment(Client* client_ptr) {
	int input;
	std::cout << "\t\t" << "\033[1;31mYour total cost: $";
	std::cout << client_ptr->koszyk.getTotalPrice();
		std::cout << " \033[0m" << std::endl << std::endl;
	std::cout << "\nPlease choose payment method:\n";
	std::cout << "1 - PayPal\n";
	std::cout << "2 - Credit Card\n";
	std::cout << ">> ";
	std::cin >> input;

	std::cout << "\nYour order is complete. Please wait for an email with payment confirmation.\n\n";
}

void Shop::summaryOfOrder(Client* client_ptr) {
	std::cout << std::endl;
	client_ptr->koszyk.printCart();
	std::cout << "\t\t"<<"\033[1;31mYour total cost: $";
	std::cout << client_ptr->koszyk.getTotalPrice();
	std::cout << " \033[0m" << std::endl << std::endl;
	client_ptr->displayAddress();
	std::cout << std::endl;
}
