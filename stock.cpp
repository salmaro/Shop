
#include "stock.h"



Stock::Stock() {
	

	Product sekator(30, "Sekator", "OGROD", "Sharp");
	Product kosiarka(1200, "Kosiarka", "OGROD", "Parkside");
	Product myjka(700, "Myjka", "OGROD", "Karcher");
	Product lopata(40, "Lopata", "OGROD", "Bosch");
	Product grabie(30, "Sekator", "OGROD", "Sharp");

	Product* sekator_ptr = &sekator;
	Product* kosiarka_ptr = &kosiarka;
	Product* myjka_ptr = &myjka;
	Product* lopata_ptr = &lopata;
	Product* grabie_ptr = &grabie;

	storage.insert({ sekator_ptr, 9 });
	storage.insert({ kosiarka_ptr, 2 });
	storage.insert({ myjka_ptr, 24 });
	storage.insert({ lopata_ptr, 5 });
	storage.insert({ grabie_ptr, 6 });

	Product telewizory(2000.00, "Telewizor","RTV", "Samsung");
	Product telefony(300.00, "Telefon", "RTV", "LG");
	Product laptopy(3000.00, "Laptop", "RTV", "Samsung");
	Product sluchawki(100.00, "Sluchawki", "RTV", "LG");
	Product radio(200.00, "Radio", "RTV", "Bosch");

	Product* telewizory_ptr{ &telewizory };
	Product* telefony_ptr{ &telefony };
	Product* laptopy_ptr{ &laptopy };
	Product* sluchawki_ptr{ &sluchawki };
	Product* radio_ptr{ &radio };

	storage.insert({ telewizory_ptr, 7 });
	storage.insert({ telefony_ptr, 5 });
	storage.insert({ laptopy_ptr, 8 });
	storage.insert({ sluchawki_ptr, 6 });
	storage.insert({ radio_ptr, 4 });

	Product lodowki(1500.00, "Lodowka", "AGD", "LG");
	Product mikrofalowki(600.00, "Mikrofalowka", "AGD", "Bosch");
	Product odkurzacze(700.00, "Odkurzacz", "AGD", "Sharp");
	Product piekarniki(1200.00, "Piekarnik", "AGD", "Bosch");
	Product pralki(2300.00, "Pralka", "AGD", "Sharp");

	Product* lodowki_ptr = &lodowki;
	Product* mikrofalowki_ptr = &mikrofalowki;
	Product* odkurzacze_ptr = &odkurzacze;
	Product* piekarniki_ptr = &piekarniki;
	Product* pralki_ptr = &pralki;

	Product samochodziki(20.00, "Samochod", "TOYS", "Sharp");
	Product klocki(200.00, "Klocki", "TOYS", "LG");
	Product lalki(40.00, "Lalka", "TOYS", "Samsung");
	Product puzzle(30.00, "Puzzle", "TOYS", "Bosch");
	Product maskotki(100.00, "Maskotka", "TOYS", "Sharp");

	storage.insert({ lodowki_ptr,5 });
	storage.insert({ mikrofalowki_ptr,5 });
	storage.insert({ odkurzacze_ptr,5 });
	storage.insert({ piekarniki_ptr,5 });
	storage.insert({ pralki_ptr,5 });

	Product* samochodziki_ptr{ &samochodziki };
	Product* klocki_ptr{ &klocki };
	Product* lalki_ptr{ &lalki};
	Product* puzzle_ptr{ &puzzle};
	Product* maskotki_ptr{ &maskotki };

	storage.insert({ samochodziki_ptr, 7 });
	storage.insert({ klocki_ptr, 5 });
	storage.insert({ lalki_ptr, 8 });
	storage.insert({ puzzle_ptr, 6 });
	storage.insert({ maskotki_ptr, 4 });
}

std::map<Product*, int> Stock::getStorage()
{
	return storage;
}
