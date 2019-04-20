#include "Lis.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


Lis::Lis(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 3;
	this->inicjatywa = 7;
	this->typ = lis;
}

void Lis::akcja()
{
	if (!czyRozmnozylSie) {					// jezeli uczestniczyl w rozmnazaniu w tej turze, to nie moze sie ruszac
		bool juzZajete = false;
		wspolrzedne nowePolozenie = losujPolozenie();
		if (!(nowePolozenie.x == polozenie.x && nowePolozenie.y == polozenie.y)) {		// aby nie wywo³ywaæ kolizji sam ze sob¹
			// DOBRY WÊCH: sprawdzenie czy dane miejsce jest wolne, czy to jest zywy organizm ORAZ czy jest silniejszy
			for (Organizm* org : swiat.getOrganizmy()) {
				if (org->getPolozenie().x == nowePolozenie.x && org->getPolozenie().y == nowePolozenie.y && org->getCzyZyje()) {
					juzZajete = true;
					if(this->sila >= org->getSila())
						kolizja(org);									// jezeli Lis jest silniejszy, wywo³aj kolizjê
					break;
				}
			}
			if (!juzZajete)					// jezeli nie zajete, to przenies sie na to pole
				polozenie = nowePolozenie;
		}
	}
}

void Lis::rysowanie() const
{
	cout << 'L';
}


Lis::~Lis()
{
}
