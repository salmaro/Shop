#include "Product.h"

Product::Product(float productPrice, std::string productName, std::string productCategory, std::string productSupplier)
	:price{ productPrice }, name{ productName }, category{ productCategory }, supplier{ productSupplier }
{

}
Product::Product()
	:Product{0,"x","x","x"}
=======
	:price(productPrice), name(productName), category(productCategory), supplier(productSupplier)
>>>>>>> 35b36c904bd8197dee37563a89751e2be58487d6
{

}

void Product::setPrice()
{
	float temp;
	std::cout << "Enter the price: ";
	std::cin >> temp;
	price = temp;
}

float Product::getPrice()
{
	return price;
}

void Product::setName()
{
	std::string temp;
	std::cout << "Enter product name: ";
	std::getline(std::cin, temp);
	name = temp;
}

std::string Product::getName()
{
	return name;
}

void Product::setCategory()
{
	std::string temp;
	std::cout << "Enter product category: ";
	std::getline(std::cin, temp);
	category = temp;
}

std::string Product::getCategory()
{
	return category;
}

void Product::setSupplier()
{
	std::string temp;
	std::cout << "Enter product supplier: ";
	std::getline(std::cin, temp);
	supplier = temp;
}

std::string Product::getSupplier()
{
	return supplier;
}