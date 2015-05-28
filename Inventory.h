#include "Item.h"
#include <SFML/Graphics.hpp>
class Inventory{

public:
	Inventory(int);
	void add(Item *);
	void show(sf::RenderWindow&);
private:
	Item** itemy;
	int wielkosc;
};