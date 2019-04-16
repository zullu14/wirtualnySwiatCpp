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
	void usunOrganizmy();
	~Swiat();

private:
	vector<Organizm*> organizmy;
	int tura;
	size_t rows, cols;
	friend bool porownajOrganizmy(Organizm* org1, Organizm* org2);
	vector<string> komunikaty;
};

