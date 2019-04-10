#pragma once
class Swiat;

class Organizm
{
public:
	struct wspolrzedne { int x, y; };
	Organizm(Swiat& srodowisko, wspolrzedne miejsce);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm& drugi) = 0;
	virtual void rysowanie() const = 0;
	virtual ~Organizm();

	int getSila() const { return sila; }
	int getInicjatywa() const { return inicjatywa; }
	int getWiek() const { return wiek;  }
	wspolrzedne getPolozenie() const { return polozenie; }

	virtual bool czyOdbilAtak(const Organizm& atakujacy);

protected:
	int sila;
	int inicjatywa;
	int wiek;
	wspolrzedne polozenie;
	Swiat& swiat;
};

