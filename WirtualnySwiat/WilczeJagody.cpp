#include "WilczeJagody.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


WilczeJagody::WilczeJagody(Swiat& srodowisko, wspolrzedne miejsce) : Roslina(srodowisko, miejsce)
{
	this->sila = 99;
	this->inicjatywa = 0;
	this->typ = jagody;
}

WilczeJagody::WilczeJagody(Swiat & srodowisko, wspolrzedne miejsce, int sila, int wiek) : Roslina(srodowisko, miejsce, sila, wiek)
{
	this->inicjatywa = 0;
	this->typ = jagody;
}

void WilczeJagody::kolizja(Organizm* drugi)
{
	drugi->setCzyZyje(false);		// po zjedzeniu wilczych jagód ka¿de zwierzê umiera
	swiat.dodajKomunikat(drugi->getTypToString() + " umiera od zjedzenia wilczych jagod na pozycji " + to_string(polozenie.x) + "," + to_string(polozenie.y));
}

void WilczeJagody::rysowanie() const
{
	cout << "x";
}


WilczeJagody::~WilczeJagody()
{
}
