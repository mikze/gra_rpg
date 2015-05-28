#include "Item.h"

Item::Item()
{

}

Item::Item(std::string _name, int _type)
{
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
