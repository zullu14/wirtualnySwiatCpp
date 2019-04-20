#include "Mlecz.h"
#include <iostream>
using namespace std;


Mlecz::Mlecz(Swiat& srodowisko, wspolrzedne miejsce) : Roslina(srodowisko, miejsce)
{
	this->sila = 0;
	this->inicjatywa = 0;
	this->typ = mlecz;
}

void Mlecz::akcja()
{
	Roslina::akcja();
	Roslina::akcja();
	Roslina::akcja();
}

void Mlecz::rysowanie() const
{
	cout << "m";
}


Mlecz::~Mlecz()
{
}
