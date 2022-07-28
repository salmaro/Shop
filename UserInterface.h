﻿#pragma once
#include<vector>
#include<string>

class UserInterface
{
	/*Produkty beda przechowywane w Stock, ktory jest wektorem 2d ( ID produktu, iloscWskaznikow = iloscProduktow)*/
	virtual void sortProductByName(const* Stock, int sortDirection/*wskaznik const na stock od andrzeja + opcja czy od a do z czy z do a*/) = 0;
	/* zwraca  wektor wskanzikow na produkty posorotowane od a do z, nic nie zwraca tylko wysietla posortowane produkty*/
	virtual void sortProductByPrice(const* Stock, int sortDirection/*wskaznik const  na stock od andrzeja + opcja czy rosnaco/ malejaco */) = 0;
	virtual void filtrBySupplier(const* Stock/*wskaznik const  na stock od andrzeja + nazwa dostawcy */) = 0;
	virtual void filtrByCategory(const* Stock) = 0;
	virtual void chooseTypeOfSorting() = 0;
	virtual void chooseTypeOfFiltering() = 0;
};
