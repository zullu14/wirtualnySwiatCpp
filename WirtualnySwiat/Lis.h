#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
public:
	Lis(Swiat& srodowisko, wspolrzedne miejsce);
	void akcja() override;
	void rysowanie() const override;
	~Lis();
};

