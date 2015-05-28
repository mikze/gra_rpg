#include "Przeciwnik.h"
#include <string>

Przeciwnik::Przeciwnik(){}

Przeciwnik::Przeciwnik(std::string _name,int _hp_max,int _mana_max,int _x,int _y)
{
	hp_max = _hp_max;
	mana_max = _mana_max;
	hp=hp_max;
	mana=mana_max;
	name=_name;
	x=_x;
	y=_y;
}
void Przeciwnik::set_lokalizacja(Lokalizacja* _lokalizacja)
{
	lokalizacja=_lokalizacja;
}
void Przeciwnik::set_hp(int _hp)
{
	hp=_hp;
}
void Przeciwnik::set_mana(int _mana)
{
	mana=_mana;
}
void Przeciwnik::set_x(int _x)
{
	x=_x;
}
void Przeciwnik::set_y(int _y)
{
	y=_y;
}
////////////////////////////////////////////////////////////////////////////////////////////
int Przeciwnik::get_hp()
{
	return hp;
}
int Przeciwnik::get_mana()
{
	return mana;
}
std::string Przeciwnik::get_name()
{
	return name;
}
Lokalizacja* Przeciwnik::get_lokalizacja()
{
	return lokalizacja;
}

int Przeciwnik::get_x()
{
	return x;
}
int Przeciwnik::get_y()
{
	return y;
}
