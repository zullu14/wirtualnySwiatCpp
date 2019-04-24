#pragma once
#include "Organizm.h"

class Roslina : public Organizm
{
public:
	Roslina(Swiat& srodowisko, wspolrzedne miejsce);
	Roslina(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	virtual void akcja() override;
	virtual void kolizja(Organizm* drugi) override;
	virtual void rysowanie() const = 0;
	virtual ~Roslina();
};

