#include "DisplayConsole.h"


void DisplayConsole::printList(Stock* stock) {

	int i{ 1 };
	std::cout << "\n\t\t\t\tSHOPePePePe\n\n";

	for (std::map<Product*, int>::iterator it = stock->getStorage()->begin(); it != stock->getStorage()->end(); it++) {
		std::cout<<std::setw(4)<<std::left << "\t" << std::setw(4) << std::left << std::to_string(i) + ". "
			<< "Product: " << std::setw(15) << std::left << it->first->getName()
			<< std::left << std::setw(10) << "Magazine: " << it->second
			<< "\tPrice: $" << it->first->getPrice() << std::endl;
		i++;
	}
}

void DisplayConsole::printWelcomeScreen() {
	std::cout << std::endl;
	std::cout << "\t+--------------------------------------------+\n";
	std::cout << "\t|                                            |\n";
	std::cout << "\t|                 SHOPePePePe                |\n";
	std::cout << "\t|                                            |\n";
	std::cout << "\t+--------------------------------------------+\n";
}

int DisplayConsole::loginAndPassword(Admin* admin, Client* client) {
	std::string userInputLogin, userInputPassword;
	std::string password{""};

	std::cout << "\n\tEnter login >> ";
	std::cin >> userInputLogin;

	std::cout << "\n\tEnter password >> ";
	maskingPassword(password);
	std::cout << std::endl << std::endl;

	if (userInputLogin == admin->getLogin() && password == admin->getPassword()) {
		return 2;
	}
	else if (userInputLogin == client->getLogin() && password == client->getPassword()) {
		return 1;
	}
	else {
		std::cout << "\n\t\t" << "\033[1;31m!!! Wrong login or password !!!\033[0m" << "\n\t\t\tTRY AGAIN\n";
		std::cin.clear();
		std::cin.ignore(100, '\n');
		return 0;
	}	
}

void DisplayConsole::maskingPassword(std::string &codeWord)
{
	char ch;

	while (1)	
	{
		ch = _getch();
		if (ch == 13)
		{
			break;		
		}
		else if (ch == 8)
		{
			codeWord.pop_back();
			printf("\b \b");
		}
		else if (ch == 32 || ch == 9)
		{
			continue;		
		}
		else
		{
			codeWord.push_back(ch);
			printf("*");
		}
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

	adminChoice = validationInput(1,3);
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

	std::cout << "\n\tWhat would you like to do?\n\n";
	std::cout << "\t1. Display all product in the shop\n";
	std::cout << "\t2. Display cart\n";
	std::cout << "\t3. Checkout\n\n\t>> ";

	int choice;
	choice = validationInput(1,3);

	if (choice == 1) {
		
		system("cls");
		printList(stock);
		std::cout << std::endl;
		std::cout << "\t1. Select products\n";
		std::cout << "\t2. Sort products\n";
		std::cout << "\t3. Filter products\n";
		std::cout << "\t4. Display cart\n ";
		std::cout << "\t5. Checkout\n\n\t>> ";

		choice = validationInput(1,4);
		if (choice == 1) {
			selectProduct(stock, client);
			if (checkOutPanel())
				return 3;
			system("cls");
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
			system("cls");
			client->koszyk.displayCart(stock);
		}
		else if (choice == 5) {
			system("cls");
			if (checkOutPanel())
				return 3;
		}

	}
	else if (choice == 2) {
		client->koszyk.displayCart(stock);
		if (checkOutPanel())
			return 3; // jezeli displayCart zwroci 1 to zwracam 3 - czyli przerywa petle w session i idzie do check out
	}
	else if (choice == 3) {
		return 3;
	}
	return -1;
}

void DisplayConsole::printTypeOfSorting(Stock* stock) {
	int choiceOfSorting;

	std::cout << "\n\t----- Choose type of sorting -----\n\n";
	std::cout << "\t1. By price  descending\n";
	std::cout << "\t2. By price  ascending\n";
	std::cout << "\t3. By name  A - Z\n";
	std::cout << "\t4. By name  Z - A\n\n\t>> ";
	
	choiceOfSorting = validationInput(1, 4);
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
		break;
	case 4:
		sortInOrder(stock, 4);
		break;
	default: std::cout << "\nThere is no such option. Try again \n\n";
	}
}

void DisplayConsole::printTypeOfFiltering(Stock* stock) {

	int choiceOfFiltering;
	int supplier{};
	int category{};

	std::cout << "\n\t----- Choose type of filtering -----\n";
	std::cout << "\t1. By category\n";
	std::cout << "\t2. By supplier\n\n>> ";
	choiceOfFiltering = validationInput(1, 2);
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

void DisplayConsole::sortPriceAscending(Stock* stock) {

	int i = 1;
	std::map<Product*, int> *magazyn1 = stock->getStorage();
	std::multimap<float, Product*, std::less<float>> magazynek;

	for (std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++) {
		magazynek.insert({ it->first->getPrice(),it->first });
	}
	for (std::multimap<float, Product*>::iterator it = magazynek.begin(); it != magazynek.end(); it++) {
		std::cout << "\t" << std::setw(4) << std::left << std::to_string(i) + ". " << std::left << "Product: " << std::setw(18) << std::left << it->second->getName()
			<< std::left << std::setw(10) << "Magazine: " << (*magazyn1)[it->second] << std::setw(15) << std::right
			<< "\tPrice: $" << it->second->getPrice() << std::endl << std::endl;
		i++;
	}
}

void DisplayConsole::filterByCategory(Stock* stock, int category) {

	std::map<Product*, int>* magazyn1 = stock->getStorage();
		int s = 1;
		for (std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++) {
			if (it->first->getCategory() == stock->getCategoryList()->at(category-1)) {
				std::cout << std::setw(4) << std::left << "\t" << std::setw(4) << std::left << std::to_string(s) + ". "
					<< "Product: " << std::setw(15) << std::left << it->first->getName()
					<< std::left  << "Magazine: " << it->second
					<< std::left  << "\tPrice: $" << it->first->getPrice() << std::endl;
				s++;
			}	
		}
		std::cout << std::endl;
}

void DisplayConsole::filterBySupplier(Stock* stock, int supplier) {

	std::map<Product*, int>* magazyn1 = stock->getStorage();
	int s = 1;
	for (std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++) {
		if (it->first->getCategory() == stock->getCategoryList()->at(supplier - 1)) {
			std::cout << std::setw(4) << std::left << "\t" << std::setw(4) << std::left << std::to_string(s) + ". "
				<< "Product: " << std::setw(15) << std::left << it->first->getName()
				<< std::left << "Magazine: " << it->second
				<< std::left << "\tPrice: $" << it->first->getPrice() << std::endl;
			s++;
		}
	}
	std::cout<< std::endl;
}

int DisplayConsole::getCategory(Stock * stock) {

	std::cout << "--- Choose category --- \n\n";

	for (size_t i{ 0 }; i < stock->getCategoryList()->size(); i++) {
		std::cout <<"\t" +std:: to_string(i+1) + ". " << stock->getCategoryList()->at(i) << std::endl;
	}
	int categoryChoose;
	categoryChoose = validationInput(1, 4);

	return categoryChoose;
}

int DisplayConsole::getSupplier(Stock* stock)
{
	std::cout << "--- Choose supplier --- \n\n";
	for (size_t i{ 0 }; i < stock->getSupplierList()->size(); i++) {
		std::cout << "\t" + std::to_string(i + 1) + ". " << stock->getSupplierList()->at(i) << std::endl;
	}
	int supplierChoose;
	supplierChoose = validationInput(1, 4);

	return supplierChoose;
}

void DisplayConsole::sortInOrder(Stock* stock, int direct) {

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
			<< "\tPrice: $" << it->second->getPrice() << std::endl << std::endl;
		i++;
	}
}

void DisplayConsole::sortPriceDescending(Stock * stock) {

	int i = 1;
	std::map<Product*, int>* magazyn1 = stock->getStorage();
	std::multimap<float, Product*, std::greater<float>> magazynek;

	for (/*std::map<Product*, int>::iterator it = magazyn1->begin(); it != magazyn1->end(); it++*/auto it: *magazyn1) {
		magazynek.insert({ it.first->getPrice(),it.first });
	}

	for (std::multimap<float, Product*>::iterator it = magazynek.begin(); it != magazynek.end(); it++) {
		std::cout << "\t" << std::setw(4) << std::left << std::to_string(i) + ". " << std::left << "Product: " << std::setw(18) << std::left << it->second->getName()
			<< std::left << std::setw(10) << "Magazine: " << (*magazyn1)[it->second] << std::setw(15) << std::right
			<< "\tPrice: $" << it->second->getPrice() << std::endl << std::endl;
		i++;
	}
}

int DisplayConsole::orderConfirmation() {

	int input;
	std::cout << "\tWhether your order is correct?" << std::endl;
	std::cout << "\t1. YES" << std::endl;
	std::cout << "\t2. NO" << std::endl;
	std::cout << "\n\n\t>> ";
	input = validationInput(1, 2);
	return input;
}

int DisplayConsole::validationInput(int start, int stop) {

	std::string output;
	bool dupy = false;

	do {
		std::getline(std::cin, output);

		for (int i = 0; i < output.size(); i++) {
			if (!isdigit(output[i])) {
				std::cout << "\t--- That was no integer! ---\n\t Please enter an integer: ";
				break;
			}
			else if (stoi(output) >= start && stoi(output) <= stop) {
				return stoi(output);
			}
			else if (stoi(output) < start || stoi(output) > stop) {
				std::cout << "\n\t--- Wrong choice, try again! ---\n\t>> ";
				break;
			}
			else
				dupy = true;
		}
	} while (!dupy);
}

void DisplayConsole::selectProduct(Stock* stock, Client* client)
{
	int helper = 0;
	do {
		int produktID;
		system("cls");
		printList(stock);
		std::cout << "\n\tEnter product ID: >> ";
		produktID = validationInput(1, 20);

		client->koszyk.addProduct(produktID, stock);
		std::cout << "\n\t1. Add another product\n\t2. Show cart\n\t3. Back to main menu\n\n\t>> ";
		helper = validationInput(1, 3);
	} while (helper == 1);
	if (helper == 2)
		client->koszyk.displayCart(stock);
}

bool DisplayConsole::checkOutPanel()
{
	int val{};
	std::cout << "\tWould you like to check out?\n\t1. YES\n\t2. NO\n\n\t>> ";
	val = validationInput(1, 2);
	if (val == 1)
		return true;
	else
		return false;
}
