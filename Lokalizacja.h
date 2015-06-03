#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include "Map.h"

struct Pole
{
    sf::Sprite sprite;
    int x,y,w,h;
};

class Lokalizacja : private Map

{

public:
	Lokalizacja();
	Lokalizacja(std::string);
	std::string get_name();
	void show_map(sf::RenderWindow&,int,int);
	void show_map_2(int,int);
	void set_name(std::string);
	int get_map(int,int);
private:
	std::string name;
	sf::Sprite sprite;
	Pole poleGry[10][10];
	sf::Texture trawa_t,mur_t,woda_t;
	sf::Texture gracz_t,troll_t,pies_t,lucznik_tucznik_t,mongolian_king_t;
	sf::Texture bron1_t;
};
