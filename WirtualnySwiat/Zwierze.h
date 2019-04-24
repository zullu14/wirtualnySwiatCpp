#pragma once
#include "Organizm.h"

class Zwierze : public Organizm
{
public:
	Zwierze(Swiat& srodowisko, wspolrzedne miejsce);
	Zwierze(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	virtual void akcja() override;
	virtual void kolizja(Organizm* drugi) override;
	virtual void rysowanie() const = 0;
	virtual ~Zwierze();
};

