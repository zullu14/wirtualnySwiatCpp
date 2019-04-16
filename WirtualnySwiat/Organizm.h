#pragma once
#include <string>
using namespace std;
class Swiat;
struct wspolrzedne { int x, y; };
enum rodzaj { wilk, owca, ILE_RODZAJOW };

class Organizm
{
public:
	Organizm(Swiat& srodowisko, wspolrzedne miejsce);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* drugi) = 0;
	virtual void rysowanie() const = 0;
	virtual ~Organizm();

	int getSila() const { return sila; }
	int getInicjatywa() const { return inicjatywa; }
	int getWiek() const { return wiek;  }
	wspolrzedne getPolozenie() const { return polozenie; }
	rodzaj getTyp() const { return typ; }
	string getTypToString();
	bool getCzyZyje() const { return czyZyje; }
	void setCzyZyje(bool stan) { czyZyje = stan; }

	virtual bool czyOdbilAtak(const Organizm* atakujacy);
	wspolrzedne losujPolozenie();

protected:
	int sila;
	int inicjatywa;
	int wiek;
	bool czyZyje;
	wspolrzedne polozenie;
	Swiat& swiat;
	rodzaj typ;
};

