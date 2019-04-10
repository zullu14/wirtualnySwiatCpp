#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>


Swiat::Swiat(size_t rows, size_t cols)
	: rows{rows}, cols{cols}, tura{1}
{
}

void Swiat::wykonajTure()
{
	sort(organizmy.begin(), organizmy.end(), porownajOrganizmy);
	for (Organizm* org : organizmy) {
		org->akcja();					// ERROR jezeli w trakcie dzialania usuwalismy organizmy, to sie pêtla nie spina...
	}
	// na koniec dolicz kolejn¹ turê
	tura++;
	rysujSwiat();
}

void Swiat::rysujSwiat()
{
	system("cls");
	bool czyNarysowano = false;
	for (size_t i = 0; i < cols + 2; i++)
		cout << "#";
	cout << endl;
	for (size_t i = 0; i < rows; i++) {				// dla kazdego wiersza
		cout << "#";								// na poczatku kazdego wiersza
		for (size_t j = 0; j < cols; j++) {			// dla kazdej kolumny w kazdym wierszu, tj. dla kazdej komórki
			czyNarysowano = false;
			for (Organizm* org : organizmy) {
				if (org->getPolozenie().x == i && org->getPolozenie().y == j) {
					org->rysowanie();
					czyNarysowano = true;
					break;
				}
			}
			if (!czyNarysowano) cout << " ";
		}
		cout << "#" << endl;						// na koncu kazdego wiersza
	}
	for (size_t i = 0; i < cols + 2; i++)
		cout << "#";
	cout << endl;
	cout << setw(cols + 2) << "***** Komunikaty *****" << endl;
	for (string info : komunikaty) {
		cout << info << endl;
	}
	komunikaty.clear();								// po wypisaniu komunikatow na te ture, usun je
}

void Swiat::stworzSwiat()
{
	srand(time(nullptr));
	int populacja = (rows*cols) / 10;
	int x, y, r;
	bool juzZajete = false;
	for (int i = 0; i < populacja; ) {
		x = rand() % rows;
		y = rand() % cols;
		juzZajete = false;
		for (Organizm* org : organizmy) {			// sprawdzenie czy dane miejsce jest wolne
			if (org->getPolozenie().x == x && org->getPolozenie().y == y) {
				juzZajete = true;
				break;
			}
		}
		if (!juzZajete) {							// jezeli miejsce wolne, stworz nowego Wilka w tym miejscu
			r = rand() % 2;
			switch (r)
			{
			case 0: organizmy.push_back(new Wilk(*this, { x,y }));
				break;
			case 1: organizmy.push_back(new Owca(*this, { x,y }));
				break;
			default:
				break;
			}
			
			i++;
		}
	}
	rysujSwiat();
}

void Swiat::usunOrganizm(Organizm * org)
{
	//organizmy.erase(remove(organizmy.begin(), organizmy.end(), org), organizmy.end());
}

Swiat::~Swiat()
{
	organizmy.clear();
}

bool porownajOrganizmy(Organizm * org1, Organizm * org2)
{
	if (org1->getInicjatywa() > org2->getInicjatywa())				// ten o wiekszej inicjatywie pierwszy
		return true;
	else if (org1->getInicjatywa() == org2->getInicjatywa())		// jezeli rowne, to ten starszy pierwszy
		return (org1->getWiek() < org2->getWiek());					// wiek przechowuje ture w ktorej sie urodzil, wiec mniejszy oznacza starszy
	else return false;
}
