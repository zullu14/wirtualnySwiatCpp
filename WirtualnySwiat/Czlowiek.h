#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze
{
public:
	Czlowiek(Swiat& srodowisko, wspolrzedne miejsce);
	void rysowanie() const override;
	~Czlowiek();
};

