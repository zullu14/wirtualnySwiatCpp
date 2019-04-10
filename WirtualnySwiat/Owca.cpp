#include "Owca.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


Owca::Owca(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 4;
	this->inicjatywa = 4;
	this->wiek = this->swiat.getTura();
}

void Owca::rysowanie() const
{
	cout << "O";
}


Owca::~Owca()
{
}
