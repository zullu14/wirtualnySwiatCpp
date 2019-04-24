#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
public:
	Guarana(Swiat& srodowisko, wspolrzedne miejsce);
	Guarana(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void kolizja(Organizm* drugi) override;
	void rysowanie() const override;
	~Guarana();
};

