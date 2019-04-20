#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze
{
public:
	Zolw(Swiat& srodowisko, wspolrzedne miejsce);
	void akcja() override;
	void rysowanie() const override;
	bool czyOdbilAtak(const Organizm* atakujacy) override;
	~Zolw();
};

