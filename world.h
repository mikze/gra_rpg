#ifndef WORLD_H
#define WORLD_H
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include "Lokalizacja.h"
#include "Item.h"
#include "Gracz.h"
#include "Przeciwnik.h"
#include "Walka.h"

class world
{
    public:
        
	    
	    Item** itemy;

	    Gracz** gracze;
	    
	    Przeciwnik** przeciwnicy;

	   	Lokalizacja** lokalizacje;

	   	void show_map();

	   	void show_map_grafa(sf::RenderWindow&);

	   	void move(int,int);

        world();
        virtual ~world();
    protected:
    private:
};

#endif // WORLD_H
