#include "Shop.h"

Stock Shop::magazyn;

int Shop::session() {
	
	Admin adminek;
	adminek.setLogin("admin");
	adminek.setPassword("admin123!");
	
	Client kliencik;
	kliencik.setLogin("1");
	kliencik.setPassword("1");

	Admin* ptr_adminek{ &adminek }; // tworzymy wskaznik na obiekt klasy admin o nazwie wskaznika ptr_adminek i dajemy mu referencje do adminek *wskaznik &wskazywanie
	Client* ptr_kliencik{ &kliencik };
	
	DisplayConsole konsola;

	int authorisation = 0;
	int finish = 0;

	while (authorisation != 1 && authorisation != 2) {
		system("cls");
		konsola.printWelcomeScreen();
		authorisation = konsola.loginAndPassword(ptr_adminek, ptr_kliencik);
		Sleep(1000);
		system("cls");
	}

	if (authorisation == 1) {
		 do {
			shopping:
			finish = konsola.userPanel(ptr_kliencik, this->stock);
		 } while (finish != 3);
	}
	system("cls");
	if (kliencik.koszyk.checkoutCart(stock) == 1) {
		kliencik.setPersonalData();
		kliencik.setBillingAddress();
		int input{};
		std::cout << "\n\tWhether Billing Adress is the same as Shipping Adress? " << std::endl;
		std::cout << "\t1. YES\n\t2. NO\n\t>> ";
		std::cin >> input;
		system("cls");
		kliencik.setShippingAddress(input);
		system("cls");
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
	std::cout << "\n\tPlease choose payment method:\n";
	std::cout << "\t1. PayPal\n";
	std::cout << "\t2. Credit Card\n";
	std::cout << "\t>> ";
	std::cin >> input;
	std::cout << "\t\t PLEASE WAIT....\n";
	Sleep(1000);
	std::cout << "\n\t"<<"\033[1;32mYour order is complete.Please wait for an email with payment confirmation.\n\n"<< " \033[0m";
}

void Shop::summaryOfOrder(Client* client_ptr) {
	std::cout << std::endl;
	std::cout << "-------------------- SUMMARY ORDER ---------------------"<< std::endl;
	client_ptr->koszyk.printCart();
	std::cout << "\t\t"<<"\033[1;31mYour total cost: $";
	std::cout << client_ptr->koszyk.getTotalPrice();
	std::cout << " \033[0m" << std::endl << std::endl;
	client_ptr->displayAddress();
	std::cout << "-------------- THNAK YOU SEE YOU AGAIN!!! --------------";
	std::cout << std::endl;
}
