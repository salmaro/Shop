#include "stock.h"


Stock::Stock() {


	Product sekator(30, "Sekator", "OGROD", "Sharp");
	Product kosiarka(1200, "Kosiarka", "OGROD", "Bosch");
	Product myjka(700, "Myjka", "OGROD", "Bosch");
	Product lopata(40, "Lopata", "OGROD", "Bosch");
	Product grabie(30, "Grabie", "OGROD", "Sharp");

	sekator_ptr = new Product(sekator);
	 //products_ptr[0]={ new Product(sekator)};
	 kosiarka_ptr = new Product(kosiarka);
	 myjka_ptr = new Product(myjka);
	 lopata_ptr = new Product(lopata);
	 grabie_ptr = new Product(grabie);

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

	 telewizory_ptr = new Product(telewizory);
	 telefony_ptr = new Product(telefony);
	 laptopy_ptr = new Product(laptopy);
	 sluchawki_ptr = new Product(sluchawki);
	 radio_ptr = new Product(radio);

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

	 lodowki_ptr = new Product (lodowki);
	 mikrofalowki_ptr = new Product (mikrofalowki);
	 odkurzacze_ptr = new Product (odkurzacze);
	 piekarniki_ptr = new Product (piekarniki);
	 pralki_ptr = new Product (pralki);

	storage.insert({ lodowki_ptr,5 });
	storage.insert({ mikrofalowki_ptr,5 });
	storage.insert({ odkurzacze_ptr,5 });
	storage.insert({ piekarniki_ptr,5 });
	storage.insert({ pralki_ptr,5 });

	Product samochodziki(20.00, "Samochod", "TOYS", "Sharp");
	Product klocki(200.00, "Klocki", "TOYS", "LG");
	Product lalki(40.00, "Lalka", "TOYS", "Samsung");
	Product puzzle(30.00, "Puzzle", "TOYS", "Bosch");
	Product maskotki(100.00, "Maskotka", "TOYS", "Sharp");

	 samochodziki_ptr = new Product(samochodziki);
	 klocki_ptr = new Product(klocki);
	 lalki_ptr = new Product(lalki);
	 puzzle_ptr = new Product(puzzle);
	 maskotki_ptr = new Product (maskotki );

	storage.insert({ samochodziki_ptr, 7 });
	storage.insert({ klocki_ptr, 5 });
	storage.insert({ lalki_ptr, 8 });
	storage.insert({ puzzle_ptr, 6 });
	storage.insert({ maskotki_ptr, 4 });

	for (std::map<Product*, int>::iterator it = storage.begin(); it != storage.end(); it++) {
		productId.push_back(it->first);
	}
}

Stock::~Stock()
{

	delete sekator_ptr;
	delete kosiarka_ptr;
	delete myjka_ptr;
	delete lopata_ptr;
	delete grabie_ptr;

	delete telewizory_ptr;
	delete telefony_ptr;
	delete laptopy_ptr;
	delete sluchawki_ptr;
	delete radio_ptr;

	delete lodowki_ptr;
	delete mikrofalowki_ptr;
	delete odkurzacze_ptr;
	delete piekarniki_ptr;
	delete pralki_ptr;

	delete samochodziki_ptr;
	delete klocki_ptr;
	delete lalki_ptr;
	delete puzzle_ptr;
	delete maskotki_ptr;

}

std::map <Product*, int >* Stock::getStorage()
{
	return &storage;
}

std::vector<Product*>* Stock::getProductID()
{
	return &productId;
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





