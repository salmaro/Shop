#include "Cart.h"

float Cart::getTotalPrice() {

	totalPrice = 0;
	for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {
		totalPrice += it->first->getPrice() * it->second;
	}
	return totalPrice;
}

void Cart::addProduct(int productID, Stock* stock) {

	Product* products = stock->getProductID();
	if (currentCart.find(products + (productID-1)) == currentCart.end()) {
		currentCart.insert({ products + (productID - 1), 1 });
		stock->subtractQuantity(products + (productID - 1));
		std::cout << "\033[1;32m" <<"\n\t\tAdd to cart product: " << (products[productID - 1]).getName() << " \033[0m" << std::endl;

	}
	else {
		++currentCart[(products + (productID - 1))];
		stock->subtractQuantity(products + (productID - 1));
		std::cout << "Add to cart product: " << (products[productID - 1]).getName() << std::endl;
	}
}

void Cart::removeProduct(Stock* stock) {

	int i = 0;
	std::cout << "Chose product to remove : \n ";
	printCart();
	int productToRemove;
	std::cout << ">> ";
	productToRemove = validationInput(1, static_cast <int> (currentCart.size()));

	for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {

		if ((productToRemove - 1) == i) {
			stock-> addQuantity(it->first,it->second);
			currentCart.erase(it);
			break;
		}
		i++;
	}
	std::cout << "\n\n \t\t Your current cart: \n";
	printCart();
}

void Cart::changeQuantity(Stock* stock) {

	int i = 0;
	std::cout << "Chose product to change : \n ";
	printCart();
	int productToChange;
	std::cout << ">> ";
	productToChange = validationInput(1, static_cast <int> (currentCart.size()));

	for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {

		if ((productToChange - 1) == i) {
			it->second--;
			stock -> addQuantity(it->first);
			break;
		}
		i++;
	}
	std::cout << "\n\n \t\t Your current cart: \n";
	this->printCart();
}

void Cart::displayCart(Stock* stock){
	
	totalPrice = {};
	size_t i{ 1 };
	if (currentCart.empty()) {
		std::cout << "\n\t\t" << "\033[1;32mYour cart is empty :( ...\n \033[0m" << std::endl;
	}
	else {
		std::cout << std::endl;
	for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {
		std::cout << i <<". Product: " << std::setw(15) << std::left << it->first->getName()
			<< std::left << std::setw(10) << "Quantity: " << it->second
			<< "\tPrice: $" << std::setw(15) << std::left << it->first->getPrice()*it->second << std::endl;
		i++;
		}
	std::cout << "\n\t\t\t\t \033[1;31mTotal Price: $" << this->getTotalPrice() << "\033[0m \n" << std::endl;
	}
	system("Pause");
	system("cls");
}

std::map<Product*, int> Cart::getCurrentCart() {
	return currentCart;
}

void Cart::cartOptions(Stock* stock) {
	std::cout << "1. Continue shopping " << std::endl;
	std::cout << "2. Edit cart " << std::endl;
	std::cout << "3. Checkout " << std::endl;
	
	int userInput{};
	userInput = validationInput(1,3);

	switch (userInput) {
	case 1:
		break;
	case 2:
		editCartOptions(stock);
		break;
	case 3:
		checkoutCart(stock);
		break;
	}
}

void Cart::editCartOptions(Stock* stock) {

	std::cout << "1. Remove product " << std::endl;
	std::cout << "2. Change quantity " << std::endl;
	std::cout << "3. Remove all product " << std::endl;

	int userInput;
	userInput = validationInput(1, 3);

	system("cls");
	size_t i{0};
	switch (userInput) {
	case 1:
		removeProduct(stock);
		break;
	case 2:
		changeQuantity(stock);
		break;
	case 3:
		break;
	}
}

void Cart::printCart() {

	int i{ 1 };

	for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {
		std::cout << i << ". Product: " << std::setw(15) << std::left << it->first->getName()
			<< std::left << std::setw(10) << "Quantity: " << it->second
			<< "\tPrice: $" << std::setw(15) << std::left << it->first->getPrice() << std::endl;
		i++;
	}
}

int Cart::checkoutCart(Stock* stock) {

	displayCart(stock);
	int input;
	std::cout << "Whether your order is correct?" << std::endl;
	std::cout << "1 - YES" << std::endl;
	std::cout << "2 - NO" << std::endl;
	std::cout << ">> ";
	input = validationInput(1, 2);
	
	return input;
}

int Cart::validationInput(int start, int stop) {

	std::string output;
	bool dupy = false;

	do {
		std::getline(std::cin, output);

		for (int i = 0; i < output.size(); i++) {
			if (!isdigit(output[i])) {
				std::cout << "That was no integer! Please enter an integer: ";
				break;
			}
			else if (stoi(output) >= start && stoi(output) <= stop) {
				return stoi(output);
			}
			else if (stoi(output) < start || stoi(output) > stop) {
				std::cout << "\n--- Wrong choice, try again! ---\n";
				break;
			}
			else
				dupy = true;
		}
	} while (!dupy);
}
