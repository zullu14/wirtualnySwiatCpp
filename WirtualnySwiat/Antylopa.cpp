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
	if (typ != drugi->getTyp() && dynamic_cast<Zwierze*>(drugi) != nullptr) {	// je¿eli s¹ ró¿nego gatunku i drugi to zwierzê, to spróbuj uciec
		polozenie.x = drugi->getPolozenie().x;			// zajmij to samo miejsce co drugi
		polozenie.y = drugi->getPolozenie().y;			// z tego samego miejsca albo ucieknie, albo jedno zginie w walce
		if (czyUciekl(drugi))
			return;										// jezeli uda³o siê uciec, to nie wykona siê kolizja Zwierz¹t
	}
	// jezeli s¹ tego samego gatunku lub drugi jest roœlin¹, lub nie uda³o siê uciec, wykonaj kolizjê Zwierz¹t
	Zwierze::kolizja(drugi);
}

void Antylopa::rysowanie() const
{
	cout << "A";
}

bool Antylopa::czyUciekl(const Organizm* atakujacy)
{
	if (!(rand() % 2)) {			// gdy bêdzie 0 spoœród 0, 1 (50% szans)
		wspolrzedne nowePolozenie = losujPolozenie();

		if (!(nowePolozenie.x == polozenie.x && nowePolozenie.y == polozenie.y)) {		// jezeli wylosowano nowe polozenie, to spróbuj uciec
			// sprawdzenie czy dane miejsce jest wolne i czy to jest zywy organizm
			for (Organizm* org : swiat.getOrganizmy()) {
				if (org->getPolozenie().x == nowePolozenie.x && org->getPolozenie().y == nowePolozenie.y && org->getCzyZyje())
					return false;									// jezeli zajete, to nie uda³o siê uciec; wyjœcie z metody
			}
			// jezeli nie zajete, to przenies sie na to pole, ucieczka udana
			swiat.dodajKomunikat("antylopa ucieka od walki z " + atakujacy->getTypToString() + " na pozycji " + to_string(polozenie.x) + "," + to_string(polozenie.y) + ". ");
			polozenie = nowePolozenie;
			return true;
		}
		else return false;					// jezeli wylosowane polozenie to stare polozenie, to nie uda³o siê uciec
	}
	else return false;
}


Antylopa::~Antylopa()
{
}
