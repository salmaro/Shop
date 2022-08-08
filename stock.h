#pragma once
#include <map>
#include "Product.h"
#include <vector>
#include <iomanip>

class Stock {
private:

	Product* products_ptr;
	std::map <Product*, int > storage;
protected:


public:
	Stock();
	~Stock();
	std::map <Product*, int >*  getStorage(); // TODO zamiast zwrocic mape, zwrocic wskaznik na mape
	Product* getProductID();
	void subtractQuantity(Product* insertProduct);
};
