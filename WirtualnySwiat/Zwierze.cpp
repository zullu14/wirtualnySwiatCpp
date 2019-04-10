#include "Zwierze.h"
#include <iostream>
using namespace std;


Zwierze::Zwierze(Swiat& srodowisko, wspolrzedne miejsce) : Organizm(srodowisko, miejsce)
{
}

void Zwierze::akcja()
{
	//TODO
}

void Zwierze::kolizja(Organizm& drugi)
{
	if (!drugi.czyOdbilAtak(*this) ) {
		if (this->sila >= drugi.getSila()) {
			// TODO: zabij cwaniaka
		}
		else {
			// TODO: spierniczasz
		}
	}
}

Zwierze::~Zwierze()
{
}
