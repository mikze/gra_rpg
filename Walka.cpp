#include "Walka.h"

Walka::Walka(Gracz* gracz,Przeciwnik* przeciwnik)
{
	lokalizacja = new Lokalizacja("Pole_walki.txt");
}

void Walka::atak()
{
	cout<<"Koniec walki "<<endl;
}