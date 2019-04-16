#include "Organizm.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Swiat.h"
#include <iostream>
using namespace std;


int main() {
	Swiat ziemia(10,30);
	ziemia.stworzSwiat();
	cout << "Zwierzat w swiecie jest " << ziemia.getOrganizmy().size() << endl;
	system("pause");

	for (int i = 0; i < 30; i++) {
		ziemia.wykonajTure();
		system("pause");
	}
	cout << "Zwierzat w swiecie jest " << ziemia.getOrganizmy().size() << endl;
	system("pause");

	return 0;
}