#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
public:
	Owca(Swiat& srodowisko, wspolrzedne miejsce);
	Owca(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void rysowanie() const override;
	~Owca();
};

