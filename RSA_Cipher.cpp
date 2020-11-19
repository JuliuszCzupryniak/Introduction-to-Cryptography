#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>


using namespace std;



void szyfruj(int tablica[10], int e_arg, int n_arg) {
	cout << "Szyfrowanie algorytmem RSA" << endl;
	int wynik=1;
	for (int i = 0; i < 10; i++) {
		wynik = 1;
		for (int j = 1; j <= e_arg; j++) {
			wynik = wynik * tablica[i];
			wynik = wynik % n_arg;
		}
		tablica[i] = wynik;
		cout << tablica[i] << " ";
	}
	cout << endl;
}

void deszyfruj(int tablica[10], int d_arg, int n_arg) {
	cout << "Deszyfrowanie zaszyfrowanego tekstu algorytmem RSA" << endl;
	int wynik=1;
	for (int i = 0; i < 10; i++){
		wynik = 1;
		for (int j = 1; j <= d_arg; j++) {
			wynik=wynik*tablica[i];
			wynik = wynik % n_arg;
		}
		tablica[i] = wynik;
		cout << tablica[i] << " ";
	}
	cout << endl;
}

















int main() {
	int p;
	int q;

	int limiter = 256;

	srand(time(NULL)); // wygenerowanie "losowego" ciagu liczb, tak naprawdę zależnego od aktualnego czasu

	
//-------------------------------------------	
start_p:
	p = rand()%limiter;
	for (int i = 2; i < p; i++) {
		if (p%i == 0) {
			goto start_p;
		}
	}
	cout << "Liczba pierwsza p: " << p << endl <<endl;
	system("pause");

//----------------------------------------------
	
	system("cls");                           

//----------------------------------------------

start_q:
	q = rand()%limiter;
	for (int i = 2; i < q; i++) {
		if (q%i == 0 || q==p) {
			goto start_q;
		}
	}
	cout << "Liczba pierwsza q: " << q << endl << endl;
	system("pause");

	if (p / q > 2 || q / p > 2) {
		cout <<endl<<"Liczby p i q leza za blisko siebie, ponowne wybranie liczb" << endl;
		system("pause");
		goto start_p;
}
//-------------------------------------------------------

	system("cls");

//-------------------------------------------------------

	int n;
	n = p * q;
	cout <<"Liczba n: "<< n<<endl<<endl;
	
	int fi;
	fi = (p - 1)*(q - 1);
	cout << "Wartosc funkcji Eulera: " << fi << endl << endl;
	system("pause");

//------------------------------------------------------------

	system("cls");

//----------------------------------------------------------
	
	int e;
	bool flag=0;

	for (int i = 2; i < fi; i++) {
		for (int j = i; j > 1; j--) {
			if (fi%j == 0 && i%j == 0) {
				flag = 1;
				break;
			}
			else {
				flag = 0;
			}
		}
		if (flag == 0) {
			e = i;
			break;
		}
	}

	cout << "Wzglednie pierwsza liczba z tocjentem: " << e <<endl;

//---------------------------------------------------------------------


	int d;
	for (int i = 1; i < fi; i++) {
		if ( (e*i) % fi == 1) {
			d = i;
			break;
		}
	}
	cout << endl << "Element odwrotny d to:  " << d << endl;
	system("pause");
	system("cls");

	int tab[10] = { 2,6,7,9,5, 3,4,5,2,8 };
//---------------------------------------------
	szyfruj(tab, e, n);

	cout << endl;

	system("pause");

	cout << endl;
//----------------------------------------------
	deszyfruj(tab, d, n);

	cout << endl;

	system("pause");

	cout << endl;
//---------------------------------------------




	cout << "Dotarles do konca programu\n";
	system("pause");
	return 0;
}
