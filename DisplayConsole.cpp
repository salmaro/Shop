#include "DisplayConsole.h"

void DisplayConsole::printList(Stock* stock)
{	
	//std::map<Product*, int>* magazyn1 = magazyn.getStorage();
	/*for (auto e: magazyn.getStorage()) {
		std::cout << std::setw(25) << "Product: " << e.first->getName()
			<< std::right << "\tMagazine: " << e.second << std::endl;
	}*/
	int i{ 1 };
	for (std::map<Product*, int>::iterator it = stock->getStorage()->begin(); it != stock->getStorage()->end(); it++) {
		std::cout<<std::setw(4)<<std::left << "\t" << std::setw(4) << std::left << std::to_string(i) + ". "
			<< "Product: " << std::setw(15) << std::left << it->first->getName()
			<< std::left << std::setw(10) << "Magazine: " << it->second
			<< "\tPrice: " << it->first->getPrice() << " $" << std::endl;
		i++;
	}
	
}

void DisplayConsole::printWelcomeScreen() {

	std::cout << "\t+--------------------------------------------+\n";
	std::cout << "\t|                                            |\n";
	std::cout << "\t|                 SHOPePePePe                |\n";
	std::cout << "\t|                                            |\n";
	std::cout << "\t+--------------------------------------------+\n";
}

int DisplayConsole::loginAndPassword(Admin* admin, Client* client) {
	std::string userInputLogin, userInputPassword;

	std::cout << "\n\tEnter login >> ";
	std::cin >> userInputLogin;

	std::cout << "\n\tEnter password >> ";
	std::cin >> userInputPassword;
	std::cout << std::endl;


	if (userInputLogin == admin->getLogin() && userInputPassword == admin->getPassword()) {
		return 2;
	}
	else if (userInputLogin == client->getLogin() && userInputPassword == client->getPassword()) {
		return 1;
	}
	else {
		std::cout << "\n\t!!! Wrong login or password !!! \nTRY AGAIN\n";
		std::cin.clear();
		std::cin.ignore(100, '\n');
		return 0;
	}	
}

void DisplayConsole::adminPanel() {

	int adminChoice{};
	system("cls");
	std::cout << "\n\tADMIN PANEL\n";
	std::cout << "\tWhat do you want to do?\n";
	std::cout << "\t\t1.Add product to stock\n";
	std::cout << "\t\t2.Remove product from stock\n";
	std::cout << "\t\t3.Reset password\n\n";

	std::cin >> adminChoice;
	std::cout << std::endl;

	switch (adminChoice) {
	case 1:
		//metoda ktora bedzie dodawac produkty do klasy Stack -->stock
		break;
	case 2:
		//metoda ktora bedzie dodawac produkty do klasy Stack -->stock
		break;
	case 3:
		//resetPassword(Client* client);
		break;
	}
}

int DisplayConsole::userPanel(Client* client, Stock* stock) {
	std::cout << "\t\t1. Display all product in the shop\n";
	std::cout << "\t\t2. Display cart\n";
	std::cout << "\t\t3. Checkout\n\n>> ";

	int choice;
	std::cin >> choice;
	std::cout << std::endl;
	std::cin.clear();
	std::cin.ignore(1000, '\n');

	if (choice == 1) {
		printList(stock);
		std::cout << std::endl;
		std::cout << "1. Select products\n";
		std::cout << "2. Sort products\n";
		std::cout << "3. Filter products\n";
		std::cout << "4. Display cart\n>> ";
		//std::cout << "5. Checkout\n\n>> ";

		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		if (choice == 1) {
			int produktID;
			std::cout << "Enter product ID: " << std::endl;
			std::cin >> produktID;

			client->koszyk.addProduct(produktID, stock);
			system("Pause");
		}
		else if (choice == 2) {
			system("cls");
			printTypeOfSorting(stock);
		}
		else if (choice == 3) {
			system("cls");
			printTypeOfFiltering(stock);
		}
		else if (choice == 4) {
			client->koszyk.displayCart();
		}

	}
	else if (choice == 2) {
		client->koszyk.displayCart();
	}
	else if (choice == 3) {
		return 3;
	}
}

void DisplayConsole::printTypeOfSorting(Stock* stock) {
	int choiceOfSorting;

	std::cout << "\n\t----- Choose type of sorting -----\n\n";
	std::cout << "\t1. By price  descending\n";
	std::cout << "\t2. By price  ascending\n";
	std::cout << "\t3. By name  A - Z\n";
	std::cout << "\t4. By name  Z - A\n\n>> ";
	std::cin >> choiceOfSorting;
	std::cout << std::endl;

	switch (choiceOfSorting) {
	case 1:
		sortPriceDescending(stock);
		break;
	case 2:
		sortPriceAscending(stock);
		break;
	case 3:
		sortInOrder(stock, 3);
		//sortInAlphabeticalOrder(stock);
		break;
	case 4:
		sortInOrder(stock, 4);
		//sortInReverseAlphabeticalOrder(stock);
		break;
	default: std::cout << "\nThere is no such option. Try again \n\n";
	}
}

void DisplayConsole::printTypeOfFiltering(Stock* stock)
{
	int choiceOfFiltering;
	int supplier{};
	int category{};

	std::cout << "\n\t----- Choose type of filtering -----\n";
	std::cout << "\t1. By category\n";
	std::cout << "\t2. By supplier\n\n>> ";
	std::cin >> choiceOfFiltering;
	std::cout << std::endl;

	switch (choiceOfFiltering) {
	case 1:
		category = getCategory(stock);
		filterByCategory(stock, category);
		break;
	case 2:
		supplier = getSupplier(stock);
		filterBySupplier(stock, supplier);
		break;
	default: std::cout << "There is no such option. Try again.\n\n";
	}
}

void DisplayConsole::sortPriceAscending(Stock* stock)
{
	int i = 1;
	std::map<Product*, int> *magazyn1 = stock->getStorage();
	std::multimap<float, Product*, std::less<float>> magazynek;

	for (std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++) {
		magazynek.insert({ it->first->getPrice(),it->first });
	}
	for (std::multimap<float, Product*>::iterator it = magazynek.begin(); it != magazynek.end(); it++) {
		std::cout << "\t" << std::setw(4) << std::left << std::to_string(i) + ". " << std::left << "Product: " << std::setw(18) << std::left << it->second->getName()
			<< std::left << std::setw(10) << "Magazine: " << (*magazyn1)[it->second] << std::setw(15) << std::right
			<< "\tPrice: " << it->second->getPrice() << " $" << std::endl << std::endl;
		i++;
	}
}

void DisplayConsole::filterByCategory(Stock* stock, int category)
{
	std::map<Product*, int>* magazyn1 = stock->getStorage();
		int s = 1;
		for (std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++) {
			if (it->first->getCategory() == stock->getCategoryList()->at(category-1)) {
				std::cout << std::setw(4) << std::left << "\t" << std::setw(4) << std::left << std::to_string(s) + ". "
					<< "Product: " << std::setw(15) << std::left << it->first->getName()
					<< std::left  << "Magazine: " << it->second
					<< std::left  << "\tPrice: " << it->first->getPrice() << " $" << std::endl;
				s++;
			}	
		}
		std::cout << std::endl;
}

void DisplayConsole::filterBySupplier(Stock* stock, int supplier)
{
	std::map<Product*, int>* magazyn1 = stock->getStorage();
	int s = 1;
	for (std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++) {
		if (it->first->getCategory() == stock->getCategoryList()->at(supplier - 1)) {
			std::cout << std::setw(4) << std::left << "\t" << std::setw(4) << std::left << std::to_string(s) + ". "
				<< "Product: " << std::setw(15) << std::left << it->first->getName()
				<< std::left << "Magazine: " << it->second
				<< std::left << "\tPrice: " << it->first->getPrice() << " $" << std::endl;
			s++;
		}
	}
	std::cout<< std::endl;
}

int DisplayConsole::getCategory(Stock * stock)
{
	std::cout << "--- Choose category --- \n\n";

	for (int i{ 0 }; i < stock->getCategoryList()->size(); i++) {
		std::cout <<"\t" +std:: to_string(i+1) + ". " << stock->getCategoryList()->at(i) << std::endl;
	}
	int categoryChoose;
	std::cin >> categoryChoose;

	return categoryChoose;
}

int DisplayConsole::getSupplier(Stock* stock)
{
	std::cout << "--- Choose supplier --- \n\n";
	for (int i{ 0 }; i < stock->getSupplierList()->size(); i++) {
		std::cout << "\t" + std::to_string(i + 1) + ". " << stock->getSupplierList()->at(i) << std::endl;
	}
	int supplierChoose;
	std::cin >> supplierChoose;

	return supplierChoose;
}

void DisplayConsole::sortInReverseAlphabeticalOrder(Stock * stock)
{
	int i = 1;
	std::map<Product*, int> *magazyn1 = stock->getStorage();
	std::multimap<std::string, Product*, std::greater<std::string>> magazynek;

	for (std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++) {
		magazynek.insert({ it->first->getName(),it->first });
	}

	for (std::multimap<std::string, Product*>::iterator it = magazynek.begin(); it != magazynek.end(); it++) {
		std::cout << "\t" << std::setw(4) << std::left << std::to_string(i) + ". " << std::left << "Product: " << std::setw(18) << std::left << it->second->getName()
			<< std::left << std::setw(10) << "Magazine: " << (*magazyn1)[it->second] << std::setw(15) << std::right
			<< "\tPrice: " << it->second->getPrice() << " $" << std::endl << std::endl;
		i++;
	}
}

void DisplayConsole::sortInAlphabeticalOrder(Stock* stock)
{
	int i = 1;
	std::map<Product*, int>* magazyn1 = stock->getStorage();
	std::multimap<std::string, Product*, std::less<std::string>> magazynek;

	for (std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++) {
		magazynek.insert({ it->first->getName(),it->first });
	}

	for (std::multimap<std::string, Product*>::iterator it = magazynek.begin(); it != magazynek.end(); it++) {
		std::cout << "\t" << std::setw(4) << std::left << std::to_string(i) + ". " << std::left << "Product: " << std::setw(18) << std::left << it->second->getName()
			<< std::left << std::setw(10) << "Magazine: " << (*magazyn1)[it->second] << std::setw(15) << std::right
			<< "\tPrice: " << it->second->getPrice() << " $" << std::endl << std::endl;
		i++;
	}
}

void DisplayConsole::sortInOrder(Stock* stock, int direct)
{
	std::map<Product*, int>* magazyn1 = stock->getStorage();
	std::multimap<std::string, Product*, std::greater<std::string>> magazynek;
	if (direct == 3) {
		std::multimap<std::string, Product*, std::greater<std::string>> magazynek;
	}
	else if (direct == 4) {
		std::multimap<std::string, Product*, std::less<std::string>> magazynek;
	}

	for (std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++) {
		magazynek.insert({ it->first->getName(),it->first });
	}
	int i{ 1 };
	for (std::multimap<std::string, Product*>::iterator it = magazynek.begin(); it != magazynek.end(); it++) {
		std::cout << "\t" << std::setw(4) << std::left << std::to_string(i) + ". " << std::left << "Product: " << std::setw(18) << std::left << it->second->getName()
			<< std::left << std::setw(10) << "Magazine: " << (*magazyn1)[it->second] << std::setw(15) << std::right
			<< "\tPrice: " << it->second->getPrice() << " $" << std::endl << std::endl;
		i++;
	}
}

void DisplayConsole::sortPriceDescending(Stock * stock)
{
	int i = 1;
	std::map<Product*, int>* magazyn1 = stock->getStorage();
	std::multimap<float, Product*, std::greater<float>> magazynek;

	for (/*std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++*/auto it: *magazyn1) {
		magazynek.insert({ it.first->getPrice(),it.first });
	}

	for (std::multimap<float, Product*>::iterator it = magazynek.begin(); it != magazynek.end(); it++) {
		std::cout << "\t" << std::setw(4) << std::left << std::to_string(i) + ". " << std::left << "Product: " << std::setw(18) << std::left << it->second->getName()
			<< std::left << std::setw(10) << "Magazine: " << (*magazyn1)[it->second] << std::setw(15) << std::right
			<< "\tPrice: " << it->second->getPrice() << " $" << std::endl << std::endl;
		i++;
	}
}

int DisplayConsole::orderConfirmation()
{
	int input;
	std::cout << "Whether your order is correct?" << std::endl;
	std::cout << "69 - YES" << std::endl;
	std::cout << "96 - NO" << std::endl;
	std::cout << ">> ";
	std::cin >> input;

	return input;

}
