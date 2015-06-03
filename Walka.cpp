#include "Walka.h"

Walka::Walka(Gracz* _gracz,Przeciwnik* _przeciwnik)
{

	gracz=_gracz;
	przeciwnik=_przeciwnik;
	lokalizacja = new Lokalizacja("Pole_walki.txt");


}

void Walka::atak()
{
	cout<<"Koniec walki "<<endl;
}