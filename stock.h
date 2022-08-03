#pragma once
#include <map>
#include "Product.h"
#include <vector>
#include <iomanip>

class Stock {
private:
	//Product* products_ptr[20];
	Product* sekator_ptr;
	Product* kosiarka_ptr;
	Product* myjka_ptr;
	Product* lopata_ptr;
	Product* grabie_ptr;

	Product* telewizory_ptr;
	Product* telefony_ptr;
	Product* laptopy_ptr;
	Product* sluchawki_ptr;
	Product* radio_ptr;

	Product* lodowki_ptr;
	Product* mikrofalowki_ptr;
	Product* odkurzacze_ptr;
	Product* piekarniki_ptr;
	Product* pralki_ptr;

	Product* samochodziki_ptr;
	Product* klocki_ptr;
	Product* lalki_ptr;
	Product* puzzle_ptr;
	Product* maskotki_ptr;

	std::vector<Product*> productId;
	std::map <Product*, int > storage;
protected:
	//static Stock magazyn;

public:
	Stock();
	~Stock();
	std::map <Product*, int >*  getStorage(); // TODO zamiast zwrocic mape, zwrocic wskaznik na mape
	std::vector<Product*> *getProductID();
	void subtractQuantity(Product* insertProduct);
};
