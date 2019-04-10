#include "Zwierze.h"
#include "Swiat.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;


Zwierze::Zwierze(Swiat& srodowisko, wspolrzedne miejsce) : Organizm(srodowisko, miejsce)
{
}

void Zwierze::akcja()
{
	bool juzZajete = false;
	int xNew, yNew;
	int r = rand() % 8;					// 8 pól na które mo¿na siê przesun¹æ
	switch (r)
	{
	case 0:
		if (polozenie.x > 0 && polozenie.y > 0) {
			xNew = polozenie.x - 1;
			yNew = polozenie.y - 1;
			break;
		}
	case 1:
		if (polozenie.x > 0) {
			xNew = polozenie.x - 1;
			yNew = polozenie.y;
			break;
		}
	case 2:
		if (polozenie.x > 0 && polozenie.y < swiat.getCols() - 1) {
			xNew = polozenie.x - 1;
			yNew = polozenie.y + 1;
			break;
		}
	case 3:
		if (polozenie.y > 0) {
			xNew = polozenie.x;
			yNew = polozenie.y - 1;
			break;
		}
	case 4:
		if (polozenie.y < swiat.getCols() - 1) {
			xNew = polozenie.x;
			yNew = polozenie.y + 1;
			break;
		}
	case 5:
		if (polozenie.x < swiat.getRows() - 1 && polozenie.y > 0) {
			xNew = polozenie.x + 1;
			yNew = polozenie.y - 1;
			break;
		}
	case 6:
		if (polozenie.x < swiat.getRows() - 1) {
			xNew = polozenie.x + 1;
			yNew = polozenie.y;
			break;
		}
	case 7:
		if (polozenie.x < swiat.getRows() - 1 && polozenie.y < swiat.getCols() - 1) {
			xNew = polozenie.x + 1;
			yNew = polozenie.y + 1;
			break;
		}
	default:
		if (polozenie.x > 0 && polozenie.y > 0) {
			xNew = polozenie.x - 1;
			yNew = polozenie.y - 1;
			break;
		}
		break;
	}  // end of switch
	for (Organizm* org : swiat.getOrganizmy()) {			// sprawdzenie czy dane miejsce jest wolne
		if (org->getPolozenie().x == xNew && org->getPolozenie().y == yNew) {
			juzZajete = true;
			kolizja(org);									// jezeli zajete, wywo³aj kolizjê
			break;
		}
	}
	if (!juzZajete) {					// jezeli nie zajete, to przenies sie na to pole
		polozenie.x = xNew;
		polozenie.y = yNew;
	}
}

void Zwierze::kolizja(Organizm* drugi)
{
	if (!drugi->czyOdbilAtak(this) ) {
		if (this->sila >= drugi->getSila()) {				// pierwszy zabija drugi organizm
			polozenie.x = drugi->getPolozenie().x;			// pierwszy zajmuje miejsce drugiego
			polozenie.y = drugi->getPolozenie().y;
			swiat.dodajKomunikat(this->typ + " zabija " + drugi->getTyp() + " na pozycji " + to_string(polozenie.x) + "," + to_string(polozenie.y) + ". ");
			swiat.usunOrganizm(drugi);						// usuniêcie drugiego z listy organizmów
		}
		else {												// na odwort: drugi zabija pierwszego
			swiat.dodajKomunikat(drugi->getTyp() + " zabija " + this->typ + " na pozycji " + to_string(drugi->getPolozenie().x) + "," + to_string(drugi->getPolozenie().y) + ". ");
			swiat.usunOrganizm(this);						// usuniêcie tego organizmu z listy organizmów
		}
	}
}

Zwierze::~Zwierze()
{
}
