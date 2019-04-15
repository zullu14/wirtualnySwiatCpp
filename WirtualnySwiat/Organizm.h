#pragma once
#include <string>
using namespace std;
class Swiat;

class Organizm
{
public:
	struct wspolrzedne { int x, y; };
	Organizm(Swiat& srodowisko, wspolrzedne miejsce);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* drugi) = 0;
	virtual void rysowanie() const = 0;
	virtual ~Organizm();

	int getSila() const { return sila; }
	int getInicjatywa() const { return inicjatywa; }
	int getWiek() const { return wiek;  }
	wspolrzedne getPolozenie() const { return polozenie; }
	string getTyp() const { return typ; }
	bool getCzyZyje() const { return czyZyje; }
	void setCzyZyje(bool stan) { czyZyje = stan; }

	virtual bool czyOdbilAtak(const Organizm* atakujacy);

protected:
	int sila;
	int inicjatywa;
	int wiek;
	bool czyZyje;
	wspolrzedne polozenie;
	Swiat& swiat;
	string typ;
};

