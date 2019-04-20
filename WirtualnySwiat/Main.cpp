#include "Organizm.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Owca.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


int main() {
	size_t w, k;
	cout << "Witaj w Wirtualnym Swiecie. " << endl
		<< "Podaj wymiary swiata - liczba wierszy: ";
	cin >> w;
	cout << "Podaj wymiary swiata - liczba kolumn: ";
	cin >> k;
	Swiat ziemia(w,k);

	ziemia.stworzSwiat();
	cout << "Zwierzat w swiecie jest " << ziemia.getOrganizmy().size() << endl;
	system("pause");

	for (int i = 0; i < 15; i++) {
	ziemia.wykonajTure();
	system("pause");
	}
	cout << "Zwierzat w swiecie jest " << ziemia.getOrganizmy().size() << endl;

	system("pause");

	return 0;
}