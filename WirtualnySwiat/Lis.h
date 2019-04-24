#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
public:
	Lis(Swiat& srodowisko, wspolrzedne miejsce);
	Lis(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void akcja() override;
	void rysowanie() const override;
	~Lis();
};

