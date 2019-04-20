#include "Roslina.h"
#include "Zwierze.h"
#include "Swiat.h"

Roslina::Roslina(Swiat& srodowisko, wspolrzedne miejsce) : Organizm(srodowisko, miejsce)
{
}

void Roslina::akcja()
{
	// ROZPRZESTRZENIANIE ROŒLIN
	if (!(rand() % 10)) {			// gdy bêdzie 0 spoœród 0-9 (10% szans)
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
}

void Roslina::kolizja(Organizm* drugi)
{
	// okreœla co siê stanie ze zwierzêciem, które zjad³o tê roœlinê; domyœlnie nic
}

Roslina::~Roslina()
{
}
