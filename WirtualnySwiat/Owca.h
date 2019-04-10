#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
public:
	Owca(Swiat& srodowisko, wspolrzedne miejsce);
	void rysowanie() const;
	~Owca();
};

