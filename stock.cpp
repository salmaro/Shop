#include "stock.h"
#include "Product.h"


Stock::Stock() {
	
	//Product::Product(float productPrice, std::string productName, std::string productCategory, std::string productSupplier)

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


}