#include "Zolw.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


Zolw::Zolw(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 2;
	this->inicjatywa = 1;
	this->typ = zolw;
}

Zolw::Zolw(Swiat & srodowisko, wspolrzedne miejsce, int sila, int wiek) : Zwierze(srodowisko, miejsce, sila, wiek)
{
	this->inicjatywa = 1;
	this->typ = zolw;
}

void Zolw::akcja()
{
	if (!(rand() % 4))			// gdy bêdzie 0 spoœród 0, 1, 2, 3 (25% szans)
		Zwierze::akcja();
}

void Zolw::rysowanie() const
{
	cout << 'Z';
}

bool Zolw::czyOdbilAtak(const Organizm * atakujacy)
{
	if (atakujacy->getSila() < 5) {
		swiat.dodajKomunikat("zolw odbil atak " + atakujacy->getTypToString() + " na pozycji " + to_string(polozenie.x) + "," + to_string(polozenie.y) + ". ");
		return true;
	}
	else return false;
}


Zolw::~Zolw()
{
}
