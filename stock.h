#include <map>
#include "Product.h"

class Stock {
public:
	Stock();
	std::map <Product*, int quantity> storage;
};