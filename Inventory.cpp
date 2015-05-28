#include "Inventory.h"
#include <iostream>

Inventory::Inventory(int a)
{
	wielkosc=a;
	itemy = new Item*[wielkosc];
	for(int i=0;i<wielkosc;i++)
		itemy[i]=NULL;
}
void Inventory::add(Item* item)
{
	for(int i=0;i<wielkosc;i++)
	{
		if(itemy[i]==NULL)
		{
			itemy[i]=item;
			break;
		}
			
	}
}

void Inventory::show(sf::RenderWindow& window)
{
	for(int i=0;i<wielkosc;i++)
	{
		if(itemy[i]!=NULL)
		std::cout<<itemy[i]->get_name()<<std::endl;
	}

}