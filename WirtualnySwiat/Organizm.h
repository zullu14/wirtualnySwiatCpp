#pragma once
#include <string>
using namespace std;
class Swiat;
struct wspolrzedne { int x, y; };
enum rodzaj { wilk, owca, zolw, lis, antylopa, trawa, mlecz, guarana, jagody, barszcz, ILE_RODZAJOW, czlowiek };

class Organizm
{
public:
	Organizm(Swiat& srodowisko, wspolrzedne miejsce);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* drugi) = 0;
	virtual void rysowanie() const = 0;
	virtual ~Organizm();

	int getSila() const { return sila; }
	void zwiekszSileO(int str) { sila += str; }
	int getInicjatywa() const { return inicjatywa; }
	int getWiek() const { return wiek;  }
	wspolrzedne getPolozenie() const { return polozenie; }
	void setPolozenie(wspolrzedne nowePolozenie) { polozenie = nowePolozenie; }
	rodzaj getTyp() const { return typ; }
	string getTypToString() const;
	bool getCzyZyje() const { return czyZyje; }
	void setCzyZyje(bool stan) { czyZyje = stan; }
	bool getCzyRozmnozylSie() const { return czyRozmnozylSie; }
	void setCzyRozmnozylSie(bool stan) { czyRozmnozylSie = stan; }

	virtual bool czyOdbilAtak(const Organizm* atakujacy);
	virtual bool czyUciekl(const Organizm* atakujacy);
	wspolrzedne losujPolozenie();

protected:
	int sila;
	int inicjatywa;
	int wiek;
	bool czyZyje;
	bool czyRozmnozylSie;
	wspolrzedne polozenie;
	Swiat& swiat;
	rodzaj typ;
};

