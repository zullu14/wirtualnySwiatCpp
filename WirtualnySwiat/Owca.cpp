#include "Owca.h"
#include <iostream>
using namespace std;


Owca::Owca(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 4;
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
