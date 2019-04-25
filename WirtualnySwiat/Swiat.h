#pragma once
#include <vector>
#include <string>
#include "Organizm.h"
using namespace std;

class Swiat
{
public:
	Swiat(size_t rows, size_t cols);
	void rozpocznijGre();
	int getTura() const { return tura; }
	int getKierunek() const { return kierunek; }
	size_t getRows() const { return rows; }
	size_t getCols() const { return cols; }
	const vector<Organizm*>& getOrganizmy() const { return organizmy; }
	const vector<Organizm*>& getNoweOrganizmy() const { return noweOrganizmy; }
	void dodajKomunikat(string info) { komunikaty.push_back(info); }
	void dodajOrganizm(rodzaj typ, wspolrzedne miejsce);
	~Swiat();

private:
	vector<Organizm*> organizmy;
	vector<Organizm*> noweOrganizmy;
	int tura;
	size_t rows, cols;
	vector<string> komunikaty;
	int kierunek;
	bool koniecGry;
	friend bool porownajOrganizmy(Organizm* org1, Organizm* org2);
	
	void wykonajTure();
	void rysujSwiat();
	void stworzSwiat();
	void dodajOrganizm(rodzaj typ, wspolrzedne miejsce, int sila, int wiek, int licznik);
	void usunOrganizmy();
	void dodajNoweOrganizmy();
	void obslugaKlawiatury();
	int piszMenu();
	void zapiszSwiat();
	bool wczytajSwiat();
	void wyczyscOrganizmy();
};

