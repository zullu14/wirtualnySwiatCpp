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

	ziemia.rozpocznijGre();

	return 0;
}