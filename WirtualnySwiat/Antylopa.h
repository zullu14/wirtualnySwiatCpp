#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze
{
public:
	Antylopa(Swiat& srodowisko, wspolrzedne miejsce);
	Antylopa(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void akcja() override;
	void kolizja(Organizm* drugi) override;
	void rysowanie() const override;
	bool czyUciekl(const Organizm* atakujacy) override;
	~Antylopa();
};

