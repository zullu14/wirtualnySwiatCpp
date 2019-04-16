#include "Zwierze.h"
#include "Swiat.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;


Zwierze::Zwierze(Swiat& srodowisko, wspolrzedne miejsce) : Organizm(srodowisko, miejsce)
{
}

void Zwierze::akcja()
{
	bool juzZajete = false;
	wspolrzedne nowePolozenie = losujPolozenie();
	for (Organizm* org : swiat.getOrganizmy()) {			// sprawdzenie czy dane miejsce jest wolne i czy to jest zywy organizm
		if (org->getPolozenie().x == nowePolozenie.x && org->getPolozenie().y == nowePolozenie.y && org->getCzyZyje()) {
			juzZajete = true;
			kolizja(org);									// jezeli zajete, wywo³aj kolizjê
			break;
		}
	}
	if (!juzZajete) {					// jezeli nie zajete, to przenies sie na to pole
		polozenie = nowePolozenie;
	}
}

void Zwierze::kolizja(Organizm* drugi)
{
	// ROZMNA¯ANIE ZWIERZ¥T
	if (typ == drugi->getTyp()) {					// jezeli zwierzêta s¹ tego samego typu - rozmnazajcie sie
		
		bool juzZajete = false;
		wspolrzedne nowePolozenie = losujPolozenie();
		for (Organizm* org : swiat.getOrganizmy()) {			// sprawdzenie czy dane miejsce jest wolne i czy to jest zywy organizm
			if (org->getPolozenie().x == nowePolozenie.x && org->getPolozenie().y == nowePolozenie.y && org->getCzyZyje())
				juzZajete = true;
		}
		if (!juzZajete) {					// jezeli nie zajete, to stworz tu nowy organizm
			swiat.dodajOrganizm(typ, nowePolozenie);
			swiat.dodajKomunikat("Nowy " + this->getTypToString() + " rodzi sie na pozycji " + to_string(nowePolozenie.x) + "," + to_string(nowePolozenie.y) + ". ");
		}
	}
	// WALKA POMIÊDZY RÓ¯NYMI ZWIERZÊTAMI
	else if (!drugi->czyOdbilAtak(this) ) {					// jak rozne to walka
		if (this->sila >= drugi->getSila()) {				// pierwszy zabija drugi organizm
			polozenie.x = drugi->getPolozenie().x;			// pierwszy zajmuje miejsce drugiego
			polozenie.y = drugi->getPolozenie().y;
			swiat.dodajKomunikat(this->getTypToString() + " zabija " + drugi->getTypToString() + " na pozycji " + to_string(polozenie.x) + "," + to_string(polozenie.y) + ". ");
			drugi->setCzyZyje(false);						// ustawienie stanu drugiego organizmu na nie¿ywy
		}
		else {												// na odwort: drugi zabija pierwszego
			swiat.dodajKomunikat(drugi->getTypToString() + " zabija " + this->getTypToString() + " na pozycji " + to_string(drugi->getPolozenie().x) + "," + to_string(drugi->getPolozenie().y) + ". ");
			this->setCzyZyje(false);						// ustawienie stanu tego organizmu na nie¿ywy
		}
	}
}

Zwierze::~Zwierze()
{
}
