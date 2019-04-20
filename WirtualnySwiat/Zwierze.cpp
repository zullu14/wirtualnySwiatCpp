#include "Zwierze.h"
#include "Swiat.h"
#include "Roslina.h"


Zwierze::Zwierze(Swiat& srodowisko, wspolrzedne miejsce) : Organizm(srodowisko, miejsce)
{
}

void Zwierze::akcja()
{
	if (!czyRozmnozylSie) {					// jezeli uczestniczyl w rozmnazaniu w tej turze, to nie moze sie ruszac
		bool juzZajete = false;
		wspolrzedne nowePolozenie = losujPolozenie();
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
}

void Zwierze::kolizja(Organizm* drugi)
{
	// ROZMNA¯ANIE ZWIERZ¥T
	if (typ == drugi->getTyp()) {					// jezeli zwierzêta s¹ tego samego typu - rozmnazajcie sie
		czyRozmnozylSie = true;
		drugi->setCzyRozmnozylSie(true);
		bool juzZajete = false;
		wspolrzedne nowePolozenie = losujPolozenie();

		for (Organizm* org : swiat.getNoweOrganizmy()) {	// sprawdzenie czy dane miejsce jest wolne na liscie nowych organizmow
			if (org->getPolozenie().x == nowePolozenie.x && org->getPolozenie().y == nowePolozenie.y) {
				juzZajete = true;
				break;
			}
		}
		if (!juzZajete) {							// jezeli miejsce wolne, stworz nowy organizm w tym miejscu
			swiat.dodajOrganizm(typ, nowePolozenie);
		}
	}
	// ZJADANIE ROŒLINY
	else if (dynamic_cast<Roslina*>(drugi) != nullptr) {	// jezeli drugi organizm jest roœlin¹
		polozenie.x = drugi->getPolozenie().x;				// zajmij miejsce roœliny
		polozenie.y = drugi->getPolozenie().y;
		drugi->kolizja(this);								// metoda kolizja() danej roœliny okreœla efekty zjedzenia jej przez zwierzêta
		drugi->setCzyZyje(false);							// ustawienie stanu roœliny na nie¿ywy
	}
	// WALKA POMIÊDZY RÓ¯NYMI ZWIERZÊTAMI
	else if (!drugi->czyOdbilAtak(this) ) {					// jak nie odbi³ ataku to walka
		polozenie.x = drugi->getPolozenie().x;				// pierwszy zajmuje miejsce drugiego
		polozenie.y = drugi->getPolozenie().y;
		if (drugi->czyUciekl(this))							// jezeli tamten uciek³, to tylko zajmij jego miejsce i wyjdŸ
			return;
		else if (this->sila >= drugi->getSila()) {			// pierwszy zabija drugi organizm		
			swiat.dodajKomunikat(this->getTypToString() + " zabija " + drugi->getTypToString() + " na pozycji " + to_string(polozenie.x) + "," + to_string(polozenie.y) + ". ");
			drugi->setCzyZyje(false);						// ustawienie stanu drugiego organizmu na nie¿ywy
		}
		else {												// na odwort: drugi zabija pierwszego
			swiat.dodajKomunikat(drugi->getTypToString() + " zabija " + this->getTypToString() + " na pozycji " + to_string(polozenie.x) + "," + to_string(polozenie.y) + ". ");
			this->setCzyZyje(false);						// ustawienie stanu tego organizmu na nie¿ywy
		}
	}
}

Zwierze::~Zwierze()
{
}
