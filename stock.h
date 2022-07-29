#pragma once
#include <map>
#include "Product.h"

class Stock {
private:
	std::map <Product*, int > storage;
public:
	Stock();
	std::map<Product*, int> getStorage(); // TODO zamiast zwrocic mape, zwrocic wskaznik na mape
};