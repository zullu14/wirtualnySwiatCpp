#include "Trawa.h"
#include <iostream>
using namespace std;


Trawa::Trawa(Swiat& srodowisko, wspolrzedne miejsce) : Roslina(srodowisko, miejsce)
{
	this->sila = 0;
	this->inicjatywa = 0;
	this->typ = trawa;
}

Trawa::Trawa(Swiat & srodowisko, wspolrzedne miejsce, int sila, int wiek) : Roslina(srodowisko, miejsce, sila, wiek)
{
	this->inicjatywa = 0;
	this->typ = trawa;
}

void Trawa::rysowanie() const
{
	cout << "t";
}


Trawa::~Trawa()
{
}
