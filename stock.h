#pragma once
#include <map>
#include "Product.h"
#include <vector>
#include <iomanip>

class Stock {
private:

	Product* products_ptr;
	std::map <Product*, int > storage;
	std::vector<std::string> category;
	std::vector<std::string> supplier;

protected:


public:
	Stock();
	~Stock();
	std::map <Product*, int >*  getStorage(); // TODO zamiast zwrocic mape, zwrocic wskaznik na mape
	Product* getProductID();
	void subtractQuantity(Product* insertProduct);
	std::vector<std::string>* getCategoryList();
	std::vector<std::string>* getSupplierList();
};


