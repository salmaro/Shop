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

	storage.insert(pro)
}