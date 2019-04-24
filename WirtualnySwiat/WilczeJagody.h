#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina
{
public:
	WilczeJagody(Swiat& srodowisko, wspolrzedne miejsce);
	WilczeJagody(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void kolizja(Organizm* drugi) override;
	void rysowanie() const override;
	~WilczeJagody();
};

