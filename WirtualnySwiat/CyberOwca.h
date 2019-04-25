#pragma once
#include "Zwierze.h"

class CyberOwca : public Zwierze
{
public:
	CyberOwca(Swiat& srodowisko, wspolrzedne miejsce);
	CyberOwca(Swiat& srodowisko, wspolrzedne miejsce, int sila, int wiek);
	void akcja() override;
	void rysowanie() const override;
	~CyberOwca();
};

