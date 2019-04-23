#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina
{
public:
	WilczeJagody(Swiat& srodowisko, wspolrzedne miejsce);
	void kolizja(Organizm* drugi) override;
	void rysowanie() const override;
	~WilczeJagody();
};

