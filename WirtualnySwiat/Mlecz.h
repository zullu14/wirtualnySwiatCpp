#pragma once
#include "Roslina.h"

class Mlecz : public Roslina
{
public:
	Mlecz(Swiat& srodowisko, wspolrzedne miejsce);
	void akcja() override;
	void rysowanie() const override;
	~Mlecz();
};

