#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze
{
public:
	Zolw(Swiat& srodowisko, wspolrzedne miejsce);
	Zolw(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void akcja() override;
	void rysowanie() const override;
	bool czyOdbilAtak(const Organizm* atakujacy) override;
	~Zolw();
};

