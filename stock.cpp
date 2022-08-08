#include "Stock.h"


Stock::Stock() {


	products_ptr = new Product[20];

	Product sekator(30, "Sekator", "OGROD", "Sharp");
	Product kosiarka(1200, "Kosiarka", "OGROD", "Bosch");
	Product myjka(700, "Myjka", "OGROD", "Bosch");
	Product lopata(40, "Lopata", "OGROD", "Bosch");
	Product grabie(30, "Grabie", "OGROD", "Sharp");

	Product telewizor(2000.00, "Telewizor", "RTV", "Samsung");
	Product telefon(300.00, "Telefon", "RTV", "LG");
	Product laptop(3000.00, "Laptop", "RTV", "Samsung");
	Product sluchawki(100.00, "Sluchawki", "RTV", "LG");
	Product radio(200.00, "Radio", "RTV", "Bosch");

	Product lodowka(1500.00, "Lodowka", "AGD", "LG");
	Product mikrofalowka(600.00, "Mikrofalowka", "AGD", "Bosch");
	Product odkurzacz(700.00, "Odkurzacz", "AGD", "Sharp");
	Product piekarnik(1200.00, "Piekarnik", "AGD", "Bosch");
	Product pralka(2300.00, "Pralka", "AGD", "Sharp");

	Product samochodzik(20.00, "Samochod", "TOYS", "Sharp");
	Product klocki(200.00, "Klocki", "TOYS", "LG");
	Product lalka(40.00, "Lalka", "TOYS", "Samsung");
	Product puzzle(30.00, "Puzzle", "TOYS", "Bosch");
	Product maskotka(100.00, "Maskotka", "TOYS", "Sharp");

	products_ptr[0] = sekator;
	products_ptr[1] = kosiarka;
	products_ptr[2] = myjka;
	products_ptr[3] = lopata;
	products_ptr[4] = grabie;

	products_ptr[5] = telewizor;
	products_ptr[6] = telefon;
	products_ptr[7] = laptop;
	products_ptr[8] = sluchawki;
	products_ptr[9] = radio;

	products_ptr[10] = lodowka;
	products_ptr[11] = mikrofalowka;
	products_ptr[12] = odkurzacz;
	products_ptr[13] = piekarnik;
	products_ptr[14] = pralka;

	products_ptr[15] = samochodzik;
	products_ptr[16] = klocki;
	products_ptr[17] = lalka;
	products_ptr[18] = puzzle;
	products_ptr[19] = maskotka;

	storage.insert({ products_ptr, 9 });
	storage.insert({ products_ptr + 1, 2 });
	storage.insert({ products_ptr + 2, 24 });
	storage.insert({ products_ptr + 3, 5 });
	storage.insert({ products_ptr + 4, 6 });

	storage.insert({ products_ptr + 5, 7 });
	storage.insert({ products_ptr + 6, 5 });
	storage.insert({ products_ptr + 7, 8 });
	storage.insert({ products_ptr + 8, 6 });
	storage.insert({ products_ptr + 9, 4 });

	storage.insert({ products_ptr + 10,5 });
	storage.insert({ products_ptr + 11,5 });
	storage.insert({ products_ptr + 12,5 });
	storage.insert({ products_ptr + 13,5 });
	storage.insert({ products_ptr + 14,5 });

	storage.insert({ products_ptr + 15, 7 });
	storage.insert({ products_ptr + 16, 5 });
	storage.insert({ products_ptr + 17, 8 });
	storage.insert({ products_ptr + 18, 6 });
	storage.insert({ products_ptr + 19, 4 });
}

Stock::~Stock()
{

	delete products_ptr;

}

std::map <Product*, int >* Stock::getStorage()
{
	return &storage;
}

//std::vector<Product*>* Stock::getProductID()
Product* Stock::getProductID()
{
	return products_ptr;
}

void Stock::subtractQuantity(Product* insertProduct)
{
	storage[insertProduct]--;
	
	/*std::cout << "jestem w substrukt, wartosc:" << insertProduct << "nazwa: " << insertProduct->getName()<<std::endl;
	size_t i{ 1 };
	for (std::map<Product*, int>::iterator it = storage.begin(); it != storage.end(); it++) {
		std::cout << std::setw(3) << std::left << std::to_string(i) + ". " << "Product: " << std::setw(15) << std::left << it->first->getName()
			<< std::left << std::setw(10) << "Magazine: " << it->second
			<< "\tPointer: " << std::setw(15) << std::left << it->first << std::endl;
		i++;
	}

	for (auto e : productId ) {
		std::cout << "wskaznik: "<<e << std::endl;
	}*/
}





