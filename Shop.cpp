#include "Shop.h"

Stock Shop::magazyn;

int Shop::session() {
	
	Admin adminek;
	adminek.setLogin("admin");
	adminek.setPassword("admin123!");
	Client kliencik;

	kliencik.setLogin("kociaczek");
	kliencik.setPassword("kociaczek");

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
		summaryOfOrder(kliencik);

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

	std::cout << "\n \033[1; 31mYour order is complete. Please wait for an email with payment confirmation.\n\n  \033[0m";
}

void Shop::summaryOfOrder(Client &client) {
	client.koszyk.printCart();
	std::cout << "\t\t"<<"\033[1;31mYour total cost: $";
	std::cout << client.koszyk.getTotalPrice();
	std::cout << " \033[0m" << std::endl << std::endl;
	client_ptr->displayAddress();
	std::cout << std::endl;
	client.displayAddress();

	std::fstream myFile;

	myFile.open("podsumowanie.csv", std::ios::out);
	
	if (!myFile.good()) {
		std::cout << "Jest kiepsko.. \n";
	}
	//for (auto it = client.koszyk.getCurrentCart().begin(); it != client.koszyk.getCurrentCart().end(); it++) {
	//	/*std::cin >> it->first->getName()
	//		>> it->first->getCategory()
	//		>> it->first->getSupplier()
	//		>> std::to_string(it->first->getPrice());*/

	for (const auto& i : client.koszyk.getCurrentCart()) {
		myFile << i.first->getName() << ", "
			<< i.first->getCategory() << ", "
			<< i.first->getSupplier() << ", "
			<< std::to_string(i.first->getPrice()) << "\n ";
	
	}

	myFile.close();

	/*std::cout << "Do you want to finish shopping?\n\n";
	std::cout << "\t1. YES\n";
	std::cout << "\t2. NO\n";

	int finishShopping{};
	std::cin >> finishShopping;

	if (finishShopping == 1) {
		std::cout << "BYE BYE!\n\n";
		exit(0);
	}*/
}
