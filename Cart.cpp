#include "Cart.h"

float Cart::getTotalPrice()
{
	for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {
		totalPrice += it->first->getPrice() * it->second;
	}
	return totalPrice;
}

void Cart::addProduct(int productID, Stock* stock)
{
	Product* products = stock->getProductID();
	if (currentCart.find(products + (productID-1)) == currentCart.end()) {
		currentCart.insert({ products + (productID - 1), 1 });
		stock->subtractQuantity(products + (productID - 1));
		std::cout << "Add to cart product: " << (products[productID - 1]).getName() << std::endl;

	}
	else {
		++currentCart[(products + (productID - 1))];
		stock->subtractQuantity(products + (productID - 1));
		std::cout << "Add to cart product: " << (products[productID - 1]).getName() << std::endl;
	}
}

void Cart::removeProduct(Stock* stock)
{
	int i = 0;
	std::cout << "Chose product to remove : \n ";
	printCart();
	int productToRemove;
	std::cout << ">> ";
	std::cin >> productToRemove;

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

void Cart::changeQuantity(Stock* stock)
{
	int i = 0;
	std::cout << "Chose product to change : \n ";
	printCart();
	int productToChange;
	std::cout << ">> ";
	std::cin >> productToChange;

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

	//if (currentCart.find(chosenProduct) == currentCart.end()) {
	//	currentCart.insert({ chosenProduct, 1 });
	//	//std::cout << "chosenProduct pointer: " << chosenProduct << std::endl;
	//	stock->addQuantity(chosenProduct);
	//}
	//else {
	//	currentCart.find(chosenProduct)->second--;
	//	stock->addQuantity(chosenProduct);
	//}
}

void Cart::displayCart(Stock* stock){
	
	size_t i{ 1 };
	if (currentCart.empty()) {
		std::cout << "Your cart is empty :( ..." << std::endl;
	}
	else {
	for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {
		std::cout << i <<". Product: " << std::setw(15) << std::left << it->first->getName()
			<< std::left << std::setw(10) << "Quantity: " << it->second
			<< "\tPrice: " << std::setw(15) << std::left << it->first->getPrice() << " $" << std::endl;
		i++;
		}
	totalPrice = {};
	std::cout << "\n\n\t\t\t\t \033[1;31mTotal Price : " << this->getTotalPrice() << " $" << "\033[0m \n\n\n" << std::endl;
	this->cartOptions(stock);
	}
	totalPrice = {};
	std::cout << "\n\n\t\t\t\t \033[1;31mTotal Price : " << this->getTotalPrice() << " $" << "\033[0m \n\n\n" << std::endl;
}

std::map<Product*, int> Cart::getCurrentCart()
{
	return currentCart;
}

void Cart::cartOptions(Stock* stock)
{
	std::cout << "1. Continue shopping " << std::endl;
	std::cout << "2. Edit cart " << std::endl;
	std::cout << "3. Checkout " << std::endl;
	
	int userInput{};
	std::cin >> userInput;


	switch (userInput) {
	case 1:

		break;
	case 2:
		editCartOptions(stock);
		break;
	case 3:
		checkoutCart();
		break;
	}
}

void Cart::editCartOptions(Stock* stock)
{
	std::cout << "1. Remove product " << std::endl;
	std::cout << "2. Change quantity " << std::endl;
	std::cout << "3. Remove all product " << std::endl;

	int userInput;
	std::cin >> userInput;

	system("cls");
	size_t i{0};
	switch (userInput) {
	case 1:
		removeProduct(stock);
		break;
	case 2:
		changeQuantity(stock);
		/*std::cout << "Change quantity: \n ";
		this->printCart();
		int productToRemoveObject;
		std::cout << ">> ";
		std::cin >> productToRemoveObject;

		for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {

			if ((productToRemoveObject - 1) == i) {
				currentCart.erase(it);
				break;
			}
			i++;
		}
		std::cout << "\n\n \t\t Your current cart: \n";
		this->printCart();*/
		break;
	case 3:
		break;

	}

}

void Cart::printCart()
{
	size_t i{ 1 };

	for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {
		std::cout << i << ". Product: " << std::setw(15) << std::left << it->first->getName()
			<< std::left << std::setw(10) << "Quantity: " << it->second
			<< "\tPrice: " << std::setw(15) << std::left << it->first->getPrice() << std::endl;
		i++;
	}
}

int Cart::checkoutCart()
{
	printCart();
	int input;
	std::cout << "Whether your order is correct?" << std::endl;
	std::cout << "69 - YES" << std::endl;
	std::cout << "96 - NO" << std::endl;
	std::cout << ">> ";
	std::cin >> input;
	
	return input;
}

//void Cart::payment()
//{
//	//total price
//	std::cout << " Your total price is: " << this->getTotalPrice() << std::endl;
//
//	std::cout << " Choose method of payment: " << std::endl;
//	
//}
