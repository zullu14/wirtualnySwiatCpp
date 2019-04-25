#include "CyberOwca.h"
#include "Sosnowski.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


CyberOwca::CyberOwca(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 11;
	this->inicjatywa = 4;
	this->typ = cyberowca;
}

CyberOwca::CyberOwca(Swiat & srodowisko, wspolrzedne miejsce, int sila, int wiek) : Zwierze(srodowisko, miejsce, sila, wiek)
{
	this->inicjatywa = 4;
	this->typ = cyberowca;
}

void CyberOwca::akcja()
{
	// ustalenie kierunku ruchu - tam gdzie pierwszy Barszcz Sosnowskiego
	wspolrzedne nowePolozenie = polozenie;
	bool czyJestBarszcz = false;
	for (Organizm* org : swiat.getOrganizmy()) {
		if (dynamic_cast<Sosnowski*>(org) != nullptr) {
			if (org->getPolozenie().x > polozenie.x) nowePolozenie.x += 1;
			else if (org->getPolozenie().x < polozenie.x) nowePolozenie.x -= 1;
			if (org->getPolozenie().y > polozenie.y) nowePolozenie.y += 1;
			else if (org->getPolozenie().y < polozenie.y) nowePolozenie.y -= 1;
			czyJestBarszcz = true;
			break;
		}
	}
	if (!czyJestBarszcz)
		nowePolozenie = losujPolozenie();				// jak nie ma barszczu na mapie, to porusza siê jak inne owce

	// wykonanie ruchu na nowe polozenie
	bool juzZajete = false;
	if (!(nowePolozenie.x == polozenie.x && nowePolozenie.y == polozenie.y)) {		// aby nie wywo³ywaæ kolizji sam ze sob¹
		for (Organizm* org : swiat.getOrganizmy()) {								// sprawdzenie czy dane miejsce jest wolne i czy to jest zywy organizm
			if (org->getPolozenie().x == nowePolozenie.x && org->getPolozenie().y == nowePolozenie.y && org->getCzyZyje()) {
				juzZajete = true;
				kolizja(org);									// jezeli zajete, wywo³aj kolizjê
				break;
			}
		}
		if (!juzZajete)					// jezeli nie zajete, to przenies sie na to pole
			polozenie = nowePolozenie;
	}
}

void CyberOwca::rysowanie() const
{
	cout << "@";
}


CyberOwca::~CyberOwca()
{
}
