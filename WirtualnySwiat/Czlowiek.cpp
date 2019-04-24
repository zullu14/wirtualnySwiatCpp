#include "Czlowiek.h"
#include "Swiat.h"
#include "stale.h"
#include <iostream>
using namespace std;


Czlowiek::Czlowiek(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 5;
	this->inicjatywa = 4;
	this->typ = czlowiek;
	this->licznikTarczy = 0;
}

void Czlowiek::akcja()
{
	if (licznikTarczy) licznikTarczy--;				// cooldown umiejêtnoœci
	bool juzZajete = false;
	wspolrzedne nowePolozenie = polozenie;
	int kierunek = swiat.getKierunek();

	switch (kierunek) {
	case prawo:
		if (nowePolozenie.y < swiat.getCols())
			nowePolozenie.y += 1;
		break;
	case lewo:
		if (nowePolozenie.y > 0)
			nowePolozenie.y -= 1;
		break;
	case gora:
		if (nowePolozenie.x > 0)
			nowePolozenie.x -= 1;
		break;
	case dol:
		if (nowePolozenie.x < swiat.getRows())
			nowePolozenie.x += 1;
		break;
	case spacja:				// obs³uga specjalnej umiejêtnoœci
		if (licznikTarczy == 0) {
			swiat.dodajKomunikat("Czlowiek aktywuje Tarcze Alzura na czas 5 tur. ");
			licznikTarczy = 10;
		}
		break;
	}
	// obsluga na wypadek kolizji
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

void Czlowiek::rysowanie() const
{
	cout << "C";
}

bool Czlowiek::czyOdbilAtak(const Organizm* atakujacy)
{
	if (licznikTarczy > 5) {
		swiat.dodajKomunikat("Czlowiek odbil atak " + atakujacy->getTypToString() + " na pozycji " + to_string(polozenie.x) + "," + to_string(polozenie.y) + ". ");
		return true;
	}
	else return false;
}


Czlowiek::~Czlowiek()
{
}
