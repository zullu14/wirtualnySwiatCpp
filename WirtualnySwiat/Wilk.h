#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze
{
public:
	Wilk(Swiat& srodowisko, wspolrzedne miejsce);
	Wilk(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void rysowanie() const override;
	~Wilk();
};

