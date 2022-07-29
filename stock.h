#pragma once
#include <map>
#include "Product.h"

class Stock {
private:
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

	std::map <Product*, int > storage;

public:
	Stock();
	~Stock();
	std::map <Product*, int >  getStorage(); // TODO zamiast zwrocic mape, zwrocic wskaznik na mape
};