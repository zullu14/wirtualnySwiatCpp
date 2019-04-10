#include "Organizm.h"
#include <iostream>
using namespace std;

Organizm::Organizm(Swiat& srodowisko, wspolrzedne miejsce)
	: swiat{srodowisko}
{
	polozenie = miejsce;
}

Organizm::~Organizm()
{
}

bool Organizm::czyOdbilAtak(const Organizm* atakujacy)
{
	return false; // domyœlnie
}
