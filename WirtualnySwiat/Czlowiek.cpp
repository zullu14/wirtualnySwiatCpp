#include "Czlowiek.h"
#include "Swiat.h"
#include "stale.h"
#include <iostream>
#include <Windows.h>
using namespace std;


Czlowiek::Czlowiek(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 5;
	this->inicjatywa = 4;
	this->typ = czlowiek;
	this->licznikTarczy = 0;
}

Czlowiek::Czlowiek(Swiat & srodowisko, wspolrzedne miejsce, int sila, int wiek, int licznik) : Zwierze(srodowisko, miejsce, sila, wiek)
{
	this->inicjatywa = 4;
	this->typ = czlowiek;
	this->licznikTarczy = licznik;
}

void Czlowiek::akcja()
{
	if (licznikTarczy) licznikTarczy--;				// cooldown umiej�tno�ci
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
	case spacja:				// obs�uga specjalnej umiej�tno�ci
		if (licznikTarczy == 0) {
			swiat.dodajKomunikat("Czlowiek aktywuje Tarcze Alzura na czas 5 tur. ");
			licznikTarczy = 10;
		}
		break;
	}
	// obsluga na wypadek kolizji
	if (!(nowePolozenie.x == polozenie.x && nowePolozenie.y == polozenie.y)) {		// aby nie wywo�ywa� kolizji sam ze sob�
		for (Organizm* org : swiat.getOrganizmy()) {								// sprawdzenie czy dane miejsce jest wolne i czy to jest zywy organizm
			if (org->getPolozenie().x == nowePolozenie.x && org->getPolozenie().y == nowePolozenie.y && org->getCzyZyje()) {
				juzZajete = true;
				kolizja(org);									// jezeli zajete, wywo�aj kolizj�
				break;
			}
		}
		if (!juzZajete)					// jezeli nie zajete, to przenies sie na to pole
			polozenie = nowePolozenie;
	}
}

void Czlowiek::rysowanie() const
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	cout << "C";
	SetConsoleTextAttribute(hConsole, 7);
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
