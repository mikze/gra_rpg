#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Jednostka.h"
#include "Item.h"

class Gracz : private Jednostka
{

public:
	Gracz();
	Gracz(std::string,int,int,int,int);
	void set_lokalizacja(Lokalizacja*);
	void set_hp(int);
	void set_mana(int);
	void set_x(int);
	void set_y(int);
	void move(int,int);
	int get_hp();
	int get_mana();
	int get_x();
	int get_y();
	void add_inv(Item*);
	void show_stats();
	void show_inv(sf::RenderWindow&);
	std::string get_name();
	Lokalizacja* get_lokalizacja();

private:


};
