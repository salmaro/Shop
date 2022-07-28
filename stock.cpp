#include "stock.h"


Stock::Stock() {
	

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

		Product Samochodziki(20.00, "Samochod", "TOYS", "Sharp");
		Product Klocki(200.00, "Klocki", "TOYS", "LG");
		Product Lalki(40.00, "Lalka", "TOYS", "Samsung");
		Product Puzzle(30.00, "Puzzle", "TOYS", "Bosch");
		Product Maskotki(100.00, "Maskotka", "TOYS", "Sharp");

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