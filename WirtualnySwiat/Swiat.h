#pragma once
#include <vector>
#include <string>
#include "Organizm.h"
using namespace std;

class Swiat
{
public:
	Swiat(size_t rows, size_t cols);
	void wykonajTure();
	void rysujSwiat();
	void stworzSwiat();
	int getTura() const { return tura; }
	size_t getRows() const { return rows; }
	size_t getCols() const { return cols; }
	const vector<Organizm*>& getOrganizmy() const { return organizmy; }
	void dodajKomunikat(string info) { komunikaty.push_back(info); }
	void dodajOrganizm(rodzaj typ, wspolrzedne miejsce);
	~Swiat();

private:
	vector<Organizm*> organizmy;
	vector<Organizm*> noweOrganizmy;
	int tura;
	size_t rows, cols;
	vector<string> komunikaty;

	friend bool porownajOrganizmy(Organizm* org1, Organizm* org2);
	
	void usunOrganizmy();
	void dodajNoweOrganizmy();
};

