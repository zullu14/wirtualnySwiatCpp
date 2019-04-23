#include "Czlowiek.h"
#include <iostream>
using namespace std;


Czlowiek::Czlowiek(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 5;
	this->inicjatywa = 4;
	this->typ = czlowiek;
}

void Czlowiek::rysowanie() const
{
	cout << "C";
}


Czlowiek::~Czlowiek()
{
}
