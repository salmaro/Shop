#include "stock.h"


Stock::Stock() {


	products_ptr = new Product[20];

	Product sekator(30.85, "Sekator", "GARDEN", "Sharp");
	Product kosiarka(1200.50, "Kosiarka", "GARDEN", "Bosch");
	Product myjka(700.75, "Myjka", "GARDEN", "Bosch");
	Product lopata(40.34, "Lopata", "GARDEN", "Bosch");
	Product grabie(30.21, "Grabie", "GARDEN", "Sharp");

	Product telewizor(2000.87, "Telewizor", "RTV", "Samsung");
	Product telefon(300.12, "Telefon", "RTV", "LG");
	Product laptop(3000.23, "Laptop", "RTV", "Samsung");
	Product sluchawki(100.11, "Sluchawki", "RTV", "LG");
	Product radio(200.09, "Radio", "RTV", "Bosch");

	Product lodowka(1500.05, "Lodowka", "AGD", "LG");
	Product mikrofalowka(599.99, "Mikrofalowka", "AGD", "Bosch");
	Product odkurzacz(700.35, "Odkurzacz", "AGD", "Sharp");
	Product piekarnik(1200.15, "Piekarnik", "AGD", "Bosch");
	Product pralka(1999.99, "Pralka", "AGD", "Sharp");

	Product samochodzik(20.50, "Samochod", "TOYS", "Sharp");
	Product klocki(199.99, "Klocki", "TOYS", "LG");
	Product lalka(45.10, "Lalka", "TOYS", "Samsung");
	Product puzzle(29.99, "Puzzle", "TOYS", "Bosch");
	Product maskotka(99.99, "Maskotka", "TOYS", "Sharp");

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

	category = { "GARDEN" , "RTV", "AGD", "TOYS" };
	supplier = { "Bosch" , "Sharp", "LG", "Samsung" };
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
	
}

void Stock::addQuantity(Product* insertProduct, int value)
{
	storage[insertProduct]+=value;
}

std::vector<std::string>* Stock::getCategoryList()
{
	return &category;
}

std::vector<std::string>* Stock::getSupplierList()
{
	return &supplier;
}





