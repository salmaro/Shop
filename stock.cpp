#include "stock.h"
#include "Product.h"


Stock::Stock() {
	

	Product Sekator(30, "Sekator", "OGROD", "Sharp");
	Product Kosiarka(1200, "Kosiarka", "OGROD", "Parkside");
	Product Myjka(700, "Myjka", "OGROD", "Karcher");
	Product Lopata(40, "Łopata", "OGROD", "Bosch");
	Product Grabie(30, "Sekator", "OGROD", "Sharp");

	Product* Sekator_ptr = &Sekator;
	Product* Kosiarka_ptr = &Kosiarka;
	Product* Myjka_ptr = &Myjka;
	Product* Lopata_ptr = &Lopata;
	Product* Grabie_ptr = &Grabie;

	storage.insert({ Sekator_ptr, 9 });
	storage.insert({ Sekator_ptr, 2 });
	storage.insert({ Sekator_ptr, 24 });
	storage.insert({ Sekator_ptr, 5 });
	storage.insert({ Sekator_ptr, 6 });

	Product Telewizory(2000.00, "Telewizor","RTV", "Samsung");
	Product Telefony(300.00, "Telefon", "RTV", "LG");
	Product Laptopy(3000.00, "Laptop", "RTV", "Samsung");
	Product Sluchawki(100.00, "Sluchawki", "RTV", "LG");
	Product Radio(200.00, "Radio", "RTV", "Bosch");

	Product* Telwizory_ptr{ &Telewizory };
	Product* Telefony_ptr{ &Telefony };
	Product* Laptopy_ptr{ &Laptopy };
	Product* Sluchawki_ptr{ &Sluchawki };
	Product* Radio_ptr{ &Radio };

	storage.insert({ Telwizory_ptr, 7 });
	storage.insert({ Telefony_ptr, 5 });
	storage.insert({ Laptopy_ptr, 8 });
	storage.insert({ Sluchawki_ptr, 6 });
	storage.insert({ Radio_ptr, 4 });

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

	Product Samochodziki(20.00, "Samochod", "TOYS", "Sharp");
	Product Klocki(200.00, "Klocki", "TOYS", "LG");
	Product Lalki(40.00, "Lalka", "TOYS", "Samsung");
	Product Puzzle(30.00, "Puzzle", "TOYS", "Bosch");
	Product Maskotki(100.00, "Maskotka", "TOYS", "Sharp");

	storage.insert({ lodowki_ptr,5 });
	storage.insert({ mikrofalowki_ptr,5 });
	storage.insert({ odkurzacze_ptr,5 });
	storage.insert({ piekarniki_ptr,5 });
	storage.insert({ pralki_ptr,5 });

	Product* Samochodziki_ptr{ &Samochodziki };
	Product* Klocki_ptr{ &Klocki };
	Product* Lalki_ptr{ &Lalki};
	Product* Puzzle_ptr{ &Puzzle};
	Product* Maskotki_ptr{ &Maskotki };

	storage.insert({ Samochodziki_ptr, 7 });
	storage.insert({ Klocki_ptr, 5 });
	storage.insert({ Lalki_ptr, 8 });
	storage.insert({ Puzzle_ptr, 6 });
	storage.insert({ Maskotki_ptr, 4 });
}