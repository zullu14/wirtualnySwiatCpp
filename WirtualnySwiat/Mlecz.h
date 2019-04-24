#pragma once
#include "Roslina.h"

class Mlecz : public Roslina
{
public:
	Mlecz(Swiat& srodowisko, wspolrzedne miejsce);
	Mlecz(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void akcja() override;
	void rysowanie() const override;
	~Mlecz();
};

