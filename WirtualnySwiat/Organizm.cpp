#include "Organizm.h"
#include "Swiat.h"
#include <iostream>
using namespace std;

Organizm::Organizm(Swiat& srodowisko, wspolrzedne miejsce)
	: swiat{srodowisko}
{
	polozenie = miejsce;
	czyZyje = true;
	czyRozmnozylSie = false;
	wiek = swiat.getTura();
}

Organizm::Organizm(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek)
	: swiat{srodowisko}, sila{sila}, wiek{wiek}
{
	polozenie = miejsce;
	czyZyje = true;
	czyRozmnozylSie = false;
}

Organizm::~Organizm()
{
}

string Organizm::getTypToString() const
{
	switch (typ)
	{
	case wilk:
		return "wilk";
	case owca:
		return "owca";
	case zolw:
		return "zolw";
	case lis:
		return "lis";
	case antylopa:
		return "antylopa";
	case trawa:
		return "trawa";
	case mlecz:
		return "mlecz";
	case guarana:
		return "guarana";
	case jagody:
		return "wilcze jagody";
	case barszcz:
		return "barszcz Sosnowskiego";
	case czlowiek:
		return "Czlowiek";
	case cyberowca:
		return "cyber-owca";
	default:
		return "obcy";
	}
}

bool Organizm::czyOdbilAtak(const Organizm* atakujacy)
{
	return false; // domyœlnie
}

bool Organizm::czyUciekl(const Organizm* atakujacy)
{
	return false; // domyœlnie
}

wspolrzedne Organizm::losujPolozenie()
{
	int xNew = polozenie.x, yNew = polozenie.y;
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
	return {xNew, yNew};
}
