#include "Guarana.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


Guarana::Guarana(Swiat& srodowisko, wspolrzedne miejsce) : Roslina(srodowisko, miejsce)
{
	this->sila = 0;
	this->inicjatywa = 0;
	this->typ = guarana;
}

void Guarana::kolizja(Organizm* drugi)
{
	drugi->zwiekszSileO(3);
	swiat.dodajKomunikat(drugi->getTypToString() + " zjada guarane na pozycji " + to_string(polozenie.x) + "," + to_string(polozenie.y) + " i zwieksza sile o 3. ");
}

void Guarana::rysowanie() const
{
	cout << "g";
}


Guarana::~Guarana()
{
}
