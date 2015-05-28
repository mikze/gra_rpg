#pragma once
#include "Lokalizacja.h"
#include "Inventory.h"
#include <string>

class Jednostka 
{
	
public:

	std::string name;
	int hp,mana,hp_max,mana_max;
	int x,y;
	Lokalizacja* lokalizacja;
	Inventory* inventory;

private:
	

};