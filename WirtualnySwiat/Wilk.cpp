#include "Wilk.h"
#include <iostream>
using namespace std;


Wilk::Wilk(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 9;
	this->inicjatywa = 5;
	this->typ = wilk;
}

Wilk::Wilk(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek) : Zwierze(srodowisko, miejsce, sila, wiek)
{
	this->inicjatywa = 5;
	this->typ = wilk;
}

void Wilk::rysowanie() const
{
	cout << 'W';
}

Wilk::~Wilk()
{
}
