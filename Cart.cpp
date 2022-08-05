#include "Cart.h"

float Cart::getTotalPrice()
{
	for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {
		totalPrice += it->first->getPrice() * it->second;
	}
	return totalPrice;
}

void Cart::addProduct(int productID)
{
	if (currentCart.find(magazyn.products_ptr+(productID-1)) == currentCart.end()) {
		currentCart.insert({ magazyn.products_ptr + (productID - 1), 1 });
		//std::cout << "chosenProduct pointer: " << chosenProduct << std::endl;
		magazyn.subtractQuantity(productID);
		std::cout << "Add to cart product: " << (magazyn.products_ptr + (productID - 1))->getName() << std::endl;
	}
	else {
		currentCart.find(magazyn.products_ptr + (productID - 1))->second++;
		magazyn.subtractQuantity(productID);
		std::cout << "Add to cart product: " << (magazyn.products_ptr + (productID - 1))->getName() << std::endl;
	}
}

void Cart::removeProduct()
{

}

void Cart::displayCart()
{
	size_t i{ 1 };
	if (currentCart.empty()) {
		std::cout << "Your cart is empty :( ..." << std::endl;
	}
	else {
	for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {
		std::cout << i <<". Product: " << std::setw(15) << std::left << it->first->getName()
			<< std::left << std::setw(10) << "Quantity: " << it->second
			<< "\tPrice: " << std::setw(15) << std::left << it->first->getPrice() << std::endl;
		i++;
		}
	totalPrice = {};
	std::cout << "\n\n\t\t\t\t \033[1;31mTotal Price : " << this->getTotalPrice() << "\033[0m \n\n\n" << std::endl;
	this->cartOptions();
	}
	totalPrice = {};
	std::cout << "\n\n\t\t\t\t \033[1;31mTotal Price : " << this->getTotalPrice() << "\033[0m \n\n\n" << std::endl;
}

std::map<Product*, int> Cart::getCurrentCart()
{
	return currentCart;
}

void Cart::cartOptions()
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
		editCartOptions();
		break;
	case 3:
		break;
	
	}
}

void Cart::editCartOptions()
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
	{
		std::cout << "Chose product to remove : \n ";
		this->printCart();
		int productToRemove;
		std::cout << ">> ";
		std::cin >> productToRemove;

		for (std::map<Product*, int>::iterator it = currentCart.begin(); it != currentCart.end(); it++) {
			if ((productToRemove - 1) == i) {
				currentCart.erase(it);
				break;
			}
			i++;
		}
		std::cout << "\n\n \t\t Your current cart: \n";
		this->printCart();
	}
		break;
	case 2:
		editCartOptions();
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

void Cart::checkoutCart()
{
	//wyswietlanie koszyka
	this->printCart();
	//opcaj wpisania danych adresowych
	std::cout << "Please enter your name:" << std::endl;
	//std::cin >> this->imie;
	std::cout << "Please enter your surname:" << std::endl;
	//std::cin >> this->nazwisko;
	std::cout << "Please enter your email:" << std::endl;
	//std::cin >> this->email;
	std::cout << "Please enter your phone number:" << std::endl;
	//std::cin >> this->phoneNumber;
	//go to payment

	//Client::BillingAddress{"Bunczy Konina", " Krakow", " 30 - 383", "Ruczaj"};
	//Client::ShippingAddress{ "Kura", " Kogut", " Kot", "Pies" };
	this -> payment();

}

void Cart::payment()
{
	//total price
	std::cout << " Your total price is: " << this->getTotalPrice() << std::endl;

	std::cout << " Choose method of payment: " << std::endl;
	
}
