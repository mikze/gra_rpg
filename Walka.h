#pragma once

#include "Gracz.h"
#include "Przeciwnik.h"
#include "Lokalizacja.h"

using namespace std;

class Walka
{

public:
	Walka(Gracz*,Przeciwnik*);
	~Walka();
	void atak();
private:
	Gracz* gracz;
	Przeciwnik* przeciwnik;
	Lokalizacja *lokalizacja;
	bool czyja_tura;
	int ktora_tura;
	

};