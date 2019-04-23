#include "Sosnowski.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


Sosnowski::Sosnowski(Swiat& srodowisko, wspolrzedne miejsce) : Roslina(srodowisko, miejsce)
{
	this->sila = 10;
	this->inicjatywa = 0;
	this->typ = barszcz;
}

void Sosnowski::akcja()
{
	for (Organizm* org : swiat.getOrganizmy()) {								// sprawdzenie czy woko³o s¹ ¿ywe organizmy
		if ((org->getPolozenie().x > polozenie.x-2 && org->getPolozenie().x < polozenie.x+2)
			&& (org->getPolozenie().y > polozenie.y-2 && org->getPolozenie().y < polozenie.y+2)
			&& org->getCzyZyje() && org != this) {
			org->setCzyZyje(false);									// jezeli zajete, wywo³aj œmieræ
			swiat.dodajKomunikat(org->getTypToString() + " zostaje zabity przez barszcz Sosnowskiego na pozycji "
				+ to_string(org->getPolozenie().x) + "," + to_string(org->getPolozenie().y));
		}
	}
}

void Sosnowski::kolizja(Organizm* drugi)
{
	drugi->setCzyZyje(false);		// po zjedzeniu barszczu Sosnowskiego ka¿de zwierzê umiera
	swiat.dodajKomunikat(drugi->getTypToString() + " umiera od zjedzenia barszczu Sosnowskiego na pozycji "
		+ to_string(polozenie.x) + "," + to_string(polozenie.y));

}

void Sosnowski::rysowanie() const
{
	cout << "&";
}


Sosnowski::~Sosnowski()
{
}
