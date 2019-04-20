#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze
{
public:
	Antylopa(Swiat& srodowisko, wspolrzedne miejsce);
	void akcja() override;
	void kolizja(Organizm* drugi) override;
	void rysowanie() const override;
	bool czyUciekl(const Organizm* atakujacy) override;
	~Antylopa();
};

