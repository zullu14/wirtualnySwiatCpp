#pragma once
#include "Roslina.h"

class Trawa : public Roslina
{
public:
	Trawa(Swiat& srodowisko, wspolrzedne miejsce);
	void rysowanie() const override;
	~Trawa();
};

