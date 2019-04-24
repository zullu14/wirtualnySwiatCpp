#pragma once
#include "Roslina.h"

class Sosnowski : public Roslina
{
public:
	Sosnowski(Swiat& srodowisko, wspolrzedne miejsce);
	Sosnowski(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void akcja() override;
	void kolizja(Organizm* drugi) override;
	void rysowanie() const override;
	~Sosnowski();
};

