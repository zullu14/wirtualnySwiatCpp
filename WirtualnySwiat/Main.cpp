#include "Organizm.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


int main() {
	Swiat ziemia(10,20);
	ziemia.stworzSwiat();
	//ziemia.rysujSwiat();

	for (Organizm* org : ziemia.getOrganizmy()) {
		org->rysowanie();
		cout << " ";
	}
	//TEST
	ziemia.wykonajTure();
	cout << endl << endl;

	for (Organizm* org : ziemia.getOrganizmy()) {
		org->rysowanie();
		cout << " ";
	}

	system("pause");
	return 0;
}