#pragma once
#include <string>

class Product
{
	float price;
	std::string name;
	std::string category;
	std::string supplier;

public:
	Product(float price, std::string name, std::string category, std::string supplier);
	void setPrice();
	float getPrice();
	void setName();
	std::string getName();
	void setCategory();
	std::string getCategory();
	void setSupplier();
	std::string getSupplier();
	void setDescription();
	std::string getDescription();

};