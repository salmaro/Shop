#include "stock.h"
#include "Product.h"


Stock::Stock() {
	
	//Product::Product(float productPrice, std::string productName, std::string productCategory, std::string productSupplier)

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

	storage.insert({ lodowki_ptr,5 });
	storage.insert({ mikrofalowki_ptr,5 });
	storage.insert({ odkurzacze_ptr,5 });
	storage.insert({ piekarniki_ptr,5 });
	storage.insert({ pralki_ptr,5 });

}