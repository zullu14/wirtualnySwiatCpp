#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze
{
public:

	Wilk(Swiat& srodowisko, wspolrzedne miejsce);
	void rysowanie() const override;
	~Wilk();
};

