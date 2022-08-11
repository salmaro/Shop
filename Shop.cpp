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
	
	if (kliencik.koszyk.checkoutCart(stock) == 1) {
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
	std::cout << "Your total price is: ";
	std::cout << client_ptr->koszyk.getTotalPrice();
	std::cout << "\nPlease choose payment method:\n";
	std::cout << "1 - PayPal\n";
	std::cout << "2 - Credit Card\n";
	std::cout << ">> ";
	std::cin >> input;

	std::cout << "\nYour order is complete. Please wait for an email with payment confirmation.\n";
}

void Shop::summaryOfOrder(Client* client_ptr) {
	client_ptr->koszyk.printCart();
	std::cout << "Your total price is: ";
	std::cout << client_ptr->koszyk.getTotalPrice();
	std::cout << std::endl;
	client_ptr->displayAddress();

	std::fstream myFile;

	myFile.open("podsumowanie.csv", std::ios::out);
	
	for (auto it = client_ptr->koszyk.getCurrentCart().begin(); it != client_ptr->koszyk.getCurrentCart().end(); it++) {
		/*std::cin >> it->first->getName()
			>> it->first->getCategory()
			>> it->first->getSupplier()
			>> std::to_string(it->first->getPrice());*/

		myFile << it->first->getName() << ", "
			<< it->first->getCategory() << ", "
			<< it->first->getSupplier() << ", "
			<< std::to_string(it->first->getPrice()) << "\n ";
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
