#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

int main() {
	
	int x; // zmienna pozwalająca określić położenie w poziomie litery na którą mam zamienić literę 
	int y; //to samo ale dla kolumny
	char szyfr; //zmienna przechowująca zaszyfrowany znak
	
	int it;
	char tab[26];
	int k = 0;
	for (it = 97; it < 123; it++) {
		tab[k] = it;
		k++;     
	}     //tworzenie statycznej listy liter alfabetu, gdzie numer komórki to liczba porządkowa litery



	int it2;
	char TAB[26];
	int k2 = 0;
	for (it2 = 65; it2 < 91; it2++) {
		TAB[k2] = it2;
		k2++;
	}      // to samo dla małych liter






	char macierz[26][26];
	char MACIERZ[26][26];

	int it3;
	int it4;
	
	for (it3 = 0; it3 < 26; it3++) {
		for (it4 = 0; it4 < 26; it4++) {
			macierz[it3][it4] = tab[((it3 + it4) % 26)];
		}
	}      //tworzenie macierzy liter, gdzie na skrzyżowaniu dwóch liter(z pliku i związanej z kluczem, szukana jest litera zaszyfrowana

	for (it3 = 0; it3 < 26; it3++) {
		for (it4 = 0; it4 < 26; it4++) {
			MACIERZ[it3][it4] = TAB[((it3 + it4) % 26)];
		}
	}   // to samo dla macierzy dużych liter


	string klucz;
	cout << "Podaj slowo kluczowe:";
	cin >> klucz;   //wprowadzenie klucza 



	ifstream plik;
	plik.open("tekst.txt", ios::in);
	char zmienna; //stąd odczytuję litery z pliku

	ofstream file;
	file.open("zaszyfrowanev.txt");

	//tutaj zapiszę szyfrogram


	unsigned licz = 0; //licznik który powie mi którą z kolei literę z klucza wziąć do pary z literą z pliku


	while (!plik.eof()) {
		plik.get(zmienna);
		szyfr = zmienna;       //przypisanie litery z pliku do zmiennej szyfr, tak aby móc ją wprowadzic do nowego pliku szyfrogram, moze byc to znak spacji lub znak ktorego sie nie szyfruje
		if (!plik.eof()) {
			if (zmienna >= 'a' && zmienna <= 'z') {
				for (int kom = 0; kom < 26; kom++) {
					if (tab[kom] == zmienna) {
						x = kom;
					}
				}                        // jesli znak to litera, szukam w ktorej kolumnie macierzy szukac zastępującego znaku
				for (int kom = 0; kom < 26; kom++) {
					if (tab[kom] == klucz.at(licz)) {
						y = kom;
					}
				} // w którym wierszu szukać zastępującego znaku (litery)
				szyfr = macierz[x][y]; //szyfr przyjmie literę an skrzyżowaniu obu liter
			}

			file << szyfr; //przesłanie litery do pliku ale i też wszelkich niezamienianych znaków

		}
		licz = (licz + 1) % (klucz.size()); //zwiększam licznik, jeśli klucz to JULEK, to do pierwszej pary dopiszę J, do drugiej U, trzeciej L itd...
	}
	return 0;
}
