#include "DisplayConsole.h"


void DisplayConsole::printWelcomeScreen(Admin* admin, Client* client) {

	std::cout << "\t+--------------------------------------------+\n";
	std::cout << "\t|                                            |\n";
	std::cout << "\t|                 SHOPePePePe                |\n";
	std::cout << "\t|                                            |\n";
	std::cout << "\t+--------------------------------------------+\n";
	loginAndPassword(admin, client);
}

void DisplayConsole::loginAndPassword(Admin* admin, Client* client) {
	std::string userInputLogin, userInputPassword;

	std::cout << "\n\tEnter login >> ";
	std::cin >> userInputLogin;

	std::cout << "\n\tEnter password >> ";
	std::cin >> userInputPassword;

	do {
		if (userInputLogin == admin->getLogin() && userInputPassword == admin->getPassword()) {
			adminPanel();
		}
		else if (userInputLogin == client->getLogin() && userInputPassword == client->getPassword()) {
			userPanel();
		}
		else {
			std::cout << "\n\t!!! Wrong login or password !!! \nTRY AGAIN\n";
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}

	} while ((userInputLogin != admin->getLogin() || userInputPassword != admin->getPassword()) ||
		(userInputLogin != client->getLogin() || userInputPassword != client->getPassword()));
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

void DisplayConsole::userPanel() {
	std::cout << "\t\t1. Display all product in the shop\n";
	std::cout << "\t\t2. Display cart\n";
	std::cout << "\t\t3. Choose category\n\n>> ";

	int choice;
	std::cin >> choice;

	switch (choice) {
	case 1:
		// print all product from stock
		break;
	case 2:
		//printCartContents();
		break;
	case 3:
		//cos tam cos tam
		break;
	}
}

void DisplayConsole::printTypeOfSorting(std::map <Product*, int> storage) {
	int choiceOfSorting;

	std::cout << "\n\t----- Choose type of sorting -----\n\n";
	std::cout << "\t1. By price  descending\n";
	std::cout << "\t2. By price  ascending\n";
	std::cout << "\t3. By name  A - Z\n";
	std::cout << "\t4. By name  Z - A\n";
	std::cin >> choiceOfSorting;

	switch (choiceOfSorting) {
	case 1:
		//sortPriceDescending(storage);
		break;
	case 2:
		sortPriceAscending( storage);
		break;
	case 3:
		//sortInAlphabeticalOrder( storage);
		break;
	case 4:
		//sortInReverseAlphabeticalOrder(storage);
		break;
	default: std::cout << "\nThere is no such option. Try again \n\n";
	}
}

void DisplayConsole::printTypeOfFiltering(std::map <Product*, int> storage)
{
	int choiceOfFiltering;

	std::cout << "\n\t----- Choose type of sorting -----\n";
	std::cout << "\t1. By category\n";
	std::cout << "\t2. By supplier\n\n";
	std::cin >> choiceOfFiltering;

	switch (choiceOfFiltering) {
	case 1:
		//filterByCategory(storage);
		break;
	case 2:
		//filterBySupplier(storage);
		break;
	default: std::cout << "There is no such option. Try again.\n\n";
	}
}

void DisplayConsole::sortPriceAscending(std::map <Product*, int> storage)
{
	//sort();
}
