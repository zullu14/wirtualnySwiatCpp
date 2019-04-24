#include "Owca.h"
#include <iostream>
using namespace std;


Owca::Owca(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 4;
	this->inicjatywa = 4;
	this->typ = owca;
}

Owca::Owca(Swiat & srodowisko, wspolrzedne miejsce, int sila, int wiek) : Zwierze(srodowisko, miejsce, sila, wiek)
{
	this->inicjatywa = 4;
	this->typ = owca;
}

void Owca::rysowanie() const
{
	cout << "O";
}


Owca::~Owca()
{
}
