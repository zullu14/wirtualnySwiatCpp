#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "Sosnowski.h"
#include "Wilk.h"
#include "Owca.h"
#include "Zolw.h"
#include "Lis.h"
#include "Antylopa.h"
#include "CyberOwca.h"
#include "Czlowiek.h"
#include "stale.h"

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iterator>
#include <conio.h>
#include <fstream>


Swiat::Swiat(size_t rows, size_t cols)
	: rows{rows}, cols{cols}, tura{0}
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

	// narysuj obecny stan œwiata wraz z komunikatami
	rysujSwiat();

	// obs³uga klawiatury
	obslugaKlawiatury();

	// na koniec dolicz kolejn¹ turê
	tura++;
}

void Swiat::rysujSwiat()
{
	system("cls");
	cout << "Projekt Wirtualny Swiat - Michal Baranowski 165463" << endl;
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
	if (tura > 0) {
		cout  << endl << "***** KOMUNIKATY *****" << endl << endl;
		for (string info : komunikaty) {
			cout << info << endl;
		}
	}
	komunikaty.clear();								// po wypisaniu komunikatow na te ture, usun je
}

void Swiat::stworzSwiat()
{
	srand(time(nullptr));							// rusza RNG
	int populacja = (rows*cols) / 14;				// ok. 7% zaludnienia
	int x, y, r;
	x = rand() % rows;
	y = rand() % cols;
	bool juzZajete = false;

	// najpierw stwórz cz³owieka i cyber-owcê
	dodajOrganizm(czlowiek, { x,y });
	while (true)
	{
		x = rand() % rows;
		y = rand() % cols;
		juzZajete = false;
		for (Organizm* &org : noweOrganizmy) {			// sprawdzenie czy dane miejsce jest wolne
			if (org->getPolozenie().x == x && org->getPolozenie().y == y) {
				juzZajete = true;
				break;
			}
		}
		if (!juzZajete) {
			dodajOrganizm(cyberowca, { x,y });
			break;										// dopiero jak dodasz cyber-owcê to wyjdŸ z pêtli while
		}
	}

	// nastêpnie stwórz resztê organizmów
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
	// obs³uga klawiatury - przed pierwsz¹ tur¹
	obslugaKlawiatury();
	tura++;
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
				dodajKomunikat("Nowe zwierze: " + nowyOrg->getTypToString() + " rodzi sie na pozycji " + to_string(nowyOrg->getPolozenie().x) + "," + to_string(nowyOrg->getPolozenie().y) + ". ");
			//else if (dynamic_cast<Roslina*>(nowyOrg) != nullptr)
				//dodajKomunikat("Nowa roslina: " + nowyOrg->getTypToString() + " wyrasta na pozycji " + to_string(nowyOrg->getPolozenie().x) + "," + to_string(nowyOrg->getPolozenie().y) + ". ");
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

void Swiat::obslugaKlawiatury()
{	
	int licznik = piszMenu();
	// próbuj tak d³ugo, a¿ zostanie wybrana strza³ka lub inne specjalne opcje
	kierunek = -1;
	unsigned char klawisz;

	while (true) {
		klawisz = _getch();
		if (klawisz == STRZALKI) {
			klawisz = _getch();
			switch (klawisz)
			{
			case PRAWO:
				kierunek = prawo;
				break;
			case LEWO:
				kierunek = lewo;
				break;
			case GORA:
				kierunek = gora;
				break;
			case DOL:
				kierunek = dol;
				break;
			}
			break;					// tylko jak by³a naciœniêta strza³ka to bêdzie wyjœcie z pêtli czytania znaków
		}
		else if (klawisz == SPACJA && licznik == 0) {			// jezeli jest mo¿liwoœæ, to zamiast ruchu mo¿na odpaliæ umiejêtnoœæ
			kierunek = spacja;
			break;					// w takim wypadku te¿ nastepuje wyjœcie z pêtli czytania znaków
		}
		else if (klawisz == 's' || klawisz == 'S') {
			zapiszSwiat();
			cout << endl << "Stan gry zapisany. " << endl;
		}
		else if (klawisz == 'l' || klawisz == 'L') {
			if (wczytajSwiat()) {			// jezeli uda³o siê wczytaæ nowy œwiat z pliku
				rysujSwiat();
				licznik = piszMenu();
			}
			else cout << endl << "Nie udalo sie wczytac stanu gry! " << endl;
		}
	}
}

int Swiat::piszMenu()
{
	cout << endl << "***** WYBOR AKCJI ***** " << endl << endl;
	bool czyCzlowiekZyje = false;
	int licznik = -1;

	// sprawdzenie czy Czlowiek zyje i spisanie licznika specjalnej umiejêtnoœci
	for (Organizm* org : organizmy) {
		if (dynamic_cast<Czlowiek*>(org) != nullptr) {
			czyCzlowiekZyje = true;
			licznik = dynamic_cast<Czlowiek*>(org)->getLicznik();
			break;
		}
	}
	if (czyCzlowiekZyje) {
		cout << "* klawisze strzalek (prawo, lewo, gora, dol) - ruch Czlowieka" << endl;
		if (licznik > 5) cout << "* Tarcza Alzura jest aktywna" << endl;
		else if (licznik > 0 && licznik <= 5) cout << "Tarcza Alzura bedzie aktywna za " << licznik << " tur" << endl;
		else if (licznik == 0) cout << "* SPACJA - aktywacja Tarczy Alzura" << endl;
	}
	else
		cout << "* klawisze strzalek - kolejna tura" << endl;
	// w obu wypadkach jeszcze opcje:
	cout << "* klawisz S - zapis stanu gry" << endl;
	cout << "* klawisz L - wczytanie ostatniego zapisu stanu gry" << endl;
	return licznik;
}

void Swiat::zapiszSwiat()
{
	ofstream plik("zapis.txt");
	int n = organizmy.size();
	
	// zapis do pliku
	plik << rows << endl;
	plik << cols << endl;
	plik << tura << endl;
	plik << n << endl;
	for (Organizm* org : organizmy) {
		plik << org->getTyp() << endl;
		plik << org->getSila() << endl;
		plik << org->getWiek() << endl;
		plik << org->getPolozenie().x << endl;
		plik << org->getPolozenie().y << endl;
		if (dynamic_cast<Czlowiek*>(org) != nullptr)
			plik << dynamic_cast<Czlowiek*>(org)->getLicznik() << endl;
	}
	plik.close();
}

bool Swiat::wczytajSwiat()
{
	ifstream plik("zapis.txt");
	if (!plik) return false;		// jesli nie uda³o siê otworzyæ pliku
	int w = 0, k = 0, ileTur, n;
	plik >> w;
	plik >> k;
	plik >> ileTur;
	plik >> n;
	if (w && k) {					// tylko jezeli swiat ma niezerowe wymiary
		wyczyscOrganizmy();			// usuwa star¹ listê organizmów, bo zape³ni now¹ z pliku
		rows = w;
		cols = k;
		tura = ileTur;
		int gatunek = 0, sila = 0, wiek = 0, x = 0, y = 0, licznik = 0;
		for (int i = 0; i < n; i++) {
			plik >> gatunek;
			plik >> sila;
			plik >> wiek;
			plik >> x;
			plik >> y;
			if (gatunek == czlowiek) plik >> licznik;
			dodajOrganizm((rodzaj)gatunek, {x,y}, sila, wiek, licznik);
		}
		plik.close();
		return true;
	}
	else {
		plik.close();
		return false;
	}

}

void Swiat::wyczyscOrganizmy()
{
	for (Organizm* &org : organizmy) {
		delete org;
		org = nullptr;
	}
	organizmy.clear();
}

void Swiat::dodajOrganizm(rodzaj typ, wspolrzedne miejsce, int sila, int wiek, int licznik = 0)
{
	// organizmy wczytywane z pliku s¹ od razu dodawane do wektora organizmy (nie przechodz¹ przez noweOrganizmy)
	switch (typ)
	{
	case wilk:
		organizmy.push_back(new Wilk(*this, miejsce, sila, wiek));
		break;
	case owca:
		organizmy.push_back(new Owca(*this, miejsce, sila, wiek));
		break;
	case zolw:
		organizmy.push_back(new Zolw(*this, miejsce, sila, wiek));
		break;
	case lis:
		organizmy.push_back(new Lis(*this, miejsce, sila, wiek));
		break;
	case antylopa:
		organizmy.push_back(new Antylopa(*this, miejsce, sila, wiek));
		break;
	case trawa:
		organizmy.push_back(new Trawa(*this, miejsce, sila, wiek));
		break;
	case mlecz:
		organizmy.push_back(new Mlecz(*this, miejsce, sila, wiek));
		break;
	case guarana:
		organizmy.push_back(new Guarana(*this, miejsce, sila, wiek));
		break;
	case jagody:
		organizmy.push_back(new WilczeJagody(*this, miejsce, sila, wiek));
		break;
	case barszcz:
		organizmy.push_back(new Sosnowski(*this, miejsce, sila, wiek));
		break;
	case czlowiek:
		organizmy.push_back(new Czlowiek(*this, miejsce, sila, wiek, licznik));
		break;
	case cyberowca:
		organizmy.push_back(new CyberOwca(*this, miejsce, sila, wiek));
		break;
	}
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
	case trawa:
		noweOrganizmy.push_back(new Trawa(*this, miejsce));
		break;
	case mlecz:
		noweOrganizmy.push_back(new Mlecz(*this, miejsce));
		break;
	case guarana:
		noweOrganizmy.push_back(new Guarana(*this, miejsce));
		break;
	case jagody:
		noweOrganizmy.push_back(new WilczeJagody(*this, miejsce));
		break;
	case barszcz:
		noweOrganizmy.push_back(new Sosnowski(*this, miejsce));
		break;
	case czlowiek:
		noweOrganizmy.push_back(new Czlowiek(*this, miejsce));
		break;
	case cyberowca:
		noweOrganizmy.push_back(new CyberOwca(*this, miejsce));
		break;
	}

}

Swiat::~Swiat()
{
	wyczyscOrganizmy();
}

bool porownajOrganizmy(Organizm * org1, Organizm * org2)
{
	if (org1->getInicjatywa() > org2->getInicjatywa())				// ten o wiekszej inicjatywie pierwszy
		return true;
	else if (org1->getInicjatywa() == org2->getInicjatywa())		// jezeli rowne, to ten starszy pierwszy
		return (org1->getWiek() < org2->getWiek());					// wiek przechowuje ture w ktorej sie urodzil, wiec mniejszy oznacza starszy
	else return false;
}
