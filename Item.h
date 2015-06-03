#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Lokalizacja.h"

class Item
{
private:
	
	int id;
	int type;
	int x,y;
	bool Grab;
	Lokalizacja *lokalizacja;
	std::string name;
	sf::Sprite sprite;

public:
	Item();
	Item(std::string,int);
	std::string get_name();
	void set_name(std::string);
	void set_lokalizacja(Lokalizacja*);
	void set_texture(sf::Texture&);
	int get_x();
	int get_y();
	void set_x(int);
	void set_y(int);
	void grab();
	void drop();

};