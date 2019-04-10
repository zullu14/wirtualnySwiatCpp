#pragma once
#include "Organizm.h"

class Roslina : public Organizm
{
public:
	virtual void akcja() override;
	virtual void kolizja(Organizm& drugi) override;
	virtual void rysowanie() const = 0;
	virtual ~Roslina();
};

