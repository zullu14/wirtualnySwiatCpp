#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Lis.h"
#include "Antylopa.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>


Swiat::Swiat(size_t rows, size_t cols)
	: rows{rows}, cols{cols}, tura{1}
{
}

void Swiat::wykonajTure()
{
	sort(organizmy.begin(), organizmy.end(), porownajOrganizmy);
	// wyzeruj flagê czyRozmnozylSie
	for (Organizm* org : organizmy)
		org->setCzyRozmnozylSie(false);
	// po kolei wykonaj akcje
	for (Organizm* org : organizmy) {
		if(org->getCzyZyje())
			org->akcja();
	}
	
	// nastêpnie usuñ z listy organizmów wszystkie nie¿ywe
	usunOrganizmy();

	// nastêpnie dodaj do listy organizmów wszystkie nowo narodzone
	dodajNoweOrganizmy();

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
			for (Organizm* &org : organizmy) {
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
	srand(time(nullptr));							// rusza RNG
	int populacja = (rows*cols) / 20;				// 5% zaludnienia
	int x, y, r;
	bool juzZajete = false;
	for (int i = 0; i < populacja; ) {
		x = rand() % rows;
		y = rand() % cols;
		juzZajete = false;
		for (Organizm* &org : noweOrganizmy) {			// sprawdzenie czy dane miejsce jest wolne
			if (org->getPolozenie().x == x && org->getPolozenie().y == y) {
				juzZajete = true;
				break;
			}
		}
		if (!juzZajete) {							// jezeli miejsce wolne, stworz nowy organizm w tym miejscu
			r = rand() % ILE_RODZAJOW;
			dodajOrganizm((rodzaj)r, { x,y });
			i++;
		}
	}
	dodajNoweOrganizmy();
	rysujSwiat();
}

void Swiat::usunOrganizmy()
{
	for (Organizm* &org : organizmy) {
		if (!(org->getCzyZyje())) {			// jezeli nie zyje
			delete org;
			org = nullptr;
		}
	}
	organizmy.erase(remove(organizmy.begin(), organizmy.end(), nullptr), organizmy.end());
}

void Swiat::dodajNoweOrganizmy()
{
	// ROZMNA¯ANIE ZWIERZ¥T/ ROZSIEWANIE ROŒLIN: Umieszczanie nowego organizmu na planszy

	bool juzZajete;
	for (Organizm* &nowyOrg : noweOrganizmy) {
		juzZajete = false;
		for (Organizm* &org : organizmy) {							// sprawdzenie, czy dane miejsce jest wolne
			if (org->getPolozenie().x == nowyOrg->getPolozenie().x && org->getPolozenie().y == nowyOrg->getPolozenie().y)
				juzZajete = true;
		}
		if (!juzZajete) {
			if (dynamic_cast<Zwierze*>(nowyOrg) != nullptr)
				dodajKomunikat("Nowy " + nowyOrg->getTypToString() + " rodzi sie na pozycji " + to_string(nowyOrg->getPolozenie().x) + "," + to_string(nowyOrg->getPolozenie().y) + ". ");
			else if (dynamic_cast<Roslina*>(nowyOrg) != nullptr)
				dodajKomunikat("Nowy " + nowyOrg->getTypToString() + " wyrasta na pozycji " + to_string(nowyOrg->getPolozenie().x) + "," + to_string(nowyOrg->getPolozenie().y) + ". ");
		}
			// jezeli miejsce zajête, to nie powstanie tu nowy organizm
		else {
			delete nowyOrg;
			nowyOrg = nullptr;
		}
	}
	noweOrganizmy.erase(remove(noweOrganizmy.begin(), noweOrganizmy.end(), nullptr), noweOrganizmy.end());
	move(noweOrganizmy.begin(), noweOrganizmy.end(), back_inserter(organizmy));
	noweOrganizmy.clear();
}

void Swiat::dodajOrganizm(rodzaj typ, wspolrzedne miejsce)
{
	switch (typ)
	{
	case wilk:
		noweOrganizmy.push_back(new Wilk(*this, miejsce));
		break;
	case owca:
		noweOrganizmy.push_back(new Owca(*this, miejsce));
		break;
	case zolw:
		noweOrganizmy.push_back(new Zolw(*this, miejsce));
		break;
	case lis:
		noweOrganizmy.push_back(new Lis(*this, miejsce));
		break;
	case antylopa:
		noweOrganizmy.push_back(new Antylopa(*this, miejsce));
		break;
	}

}

Swiat::~Swiat()
{
	for (Organizm* &org : organizmy) {
		delete org;
		org = nullptr;
	}
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
