#include "Antylopa.h"
#include "Swiat.h"
#include "Zwierze.h"
#include <iostream>
using namespace std;


Antylopa::Antylopa(Swiat& srodowisko, wspolrzedne miejsce) : Zwierze(srodowisko, miejsce)
{
	this->sila = 4;
	this->inicjatywa = 4;
	this->typ = antylopa;
}

void Antylopa::akcja()
{
	Zwierze::akcja();
	Zwierze::akcja();
}

void Antylopa::kolizja(Organizm* drugi)
{
	if (typ != drugi->getTyp() && dynamic_cast<Zwierze*>(drugi) != nullptr) {	// je�eli s� r�nego gatunku i drugi to zwierz�, to spr�buj uciec
		polozenie.x = drugi->getPolozenie().x;			// zajmij to samo miejsce co drugi
		polozenie.y = drugi->getPolozenie().y;			// z tego samego miejsca albo ucieknie, albo jedno zginie w walce
		if (czyUciekl(drugi))
			return;										// jezeli uda�o si� uciec, to nie wykona si� kolizja Zwierz�t
	}
	// jezeli s� tego samego gatunku lub drugi jest ro�lin�, lub nie uda�o si� uciec, wykonaj kolizj� Zwierz�t
	Zwierze::kolizja(drugi);
}

void Antylopa::rysowanie() const
{
	cout << "A";
}

bool Antylopa::czyUciekl(const Organizm* atakujacy)
{
	if (!(rand() % 2)) {			// gdy b�dzie 0 spo�r�d 0, 1 (50% szans)
		wspolrzedne nowePolozenie = losujPolozenie();

		if (!(nowePolozenie.x == polozenie.x && nowePolozenie.y == polozenie.y)) {		// jezeli wylosowano nowe polozenie, to spr�buj uciec
			// sprawdzenie czy dane miejsce jest wolne i czy to jest zywy organizm
			for (Organizm* org : swiat.getOrganizmy()) {
				if (org->getPolozenie().x == nowePolozenie.x && org->getPolozenie().y == nowePolozenie.y && org->getCzyZyje())
					return false;									// jezeli zajete, to nie uda�o si� uciec; wyj�cie z metody
			}
			// jezeli nie zajete, to przenies sie na to pole, ucieczka udana
			swiat.dodajKomunikat("antylopa ucieka od walki z " + atakujacy->getTypToString() + " na pozycji " + to_string(polozenie.x) + "," + to_string(polozenie.y) + ". ");
			polozenie = nowePolozenie;
			return true;
		}
		else return false;					// jezeli wylosowane polozenie to stare polozenie, to nie uda�o si� uciec
	}
	else return false;
}


Antylopa::~Antylopa()
{
}
