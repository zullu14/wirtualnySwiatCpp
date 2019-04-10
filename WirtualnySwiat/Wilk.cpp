#include "Wilk.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


Wilk::Wilk(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 9;
	this->inicjatywa = 5;
	this->wiek = this->swiat.getTura();
	this->typ = "wilk";
}

void Wilk::rysowanie() const
{
	cout << 'W';
}

Wilk::~Wilk()
{
}
