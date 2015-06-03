#include "Item.h"

Item::Item()
{

}

Item::Item(std::string _name, int _type)
{
	Grab=0;
	name=_name;
	type=_type;
}
std::string Item::get_name()
{
	return name;
}

void Item::set_name(std::string _name)
{
	name=_name;
}
void Item::set_lokalizacja(Lokalizacja* _lokalizacja)
{
	lokalizacja=_lokalizacja;
}

void Item::set_texture(sf::Texture& _textura)
{
	//sprite
}
void Item::set_x(int _x)
{
	x=_x;
}
void Item::set_y(int _y)
{
	y=_y;
}
void Item::grab()
{
	Grab=1;
}
void Item::drop()
{
	Grab=0;
}