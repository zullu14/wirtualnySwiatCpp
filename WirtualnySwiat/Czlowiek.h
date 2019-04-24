#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze
{
public:
	Czlowiek(Swiat& srodowisko, wspolrzedne miejsce);
	void akcja() override;
	void rysowanie() const override;
	bool czyOdbilAtak(const Organizm* atakujacy) override;
	~Czlowiek();
	int getLicznik() const { return licznikTarczy; }

private:
	int licznikTarczy;
};

