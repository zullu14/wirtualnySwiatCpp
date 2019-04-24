#pragma once
#include "Roslina.h"

class Trawa : public Roslina
{
public:
	Trawa(Swiat& srodowisko, wspolrzedne miejsce);
	Trawa(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void rysowanie() const override;
	~Trawa();
};

