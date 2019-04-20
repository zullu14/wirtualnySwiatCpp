#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
public:
	Guarana(Swiat& srodowisko, wspolrzedne miejsce);
	void kolizja(Organizm* drugi) override;
	void rysowanie() const override;
	~Guarana();
};

