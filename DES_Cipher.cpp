#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void S5_box_function(bool*tablica, int S5_BOX[4][16], bool*nowe) {
	int x1,x2,x;
	int y=0;
	int wartosc;
	bool pocz, kon;
	pocz = tablica[0];
	kon = tablica[5];
	if (pocz == 1) {
		x1 = 2;
	}
	if(pocz==0) {
		x1 = 0;
	}
	if (kon == 1) {
		x2 = 1;
	}
	if(kon==0) {
		x2 = 0;

	}
	x = x1 + x2;
	//========================================================
	for (int i = 1; i <= 4; i++) {
		if (tablica[i] == 1) {
			y =(int) y + pow(2, (4-i));
		}
	}
	cout <<"Wartosc dziesietna z S5 = " <<S5_BOX[x][y]<<endl;
	//========================================================
	wartosc = S5_BOX[x][y];

	if (wartosc >= 8) {
		nowe[0] = 1;
		wartosc = wartosc - 8;
		
	}
	if (wartosc >= 4) {
		nowe[1] = 1;
		wartosc = wartosc - 4;
	}
	
	if (wartosc >= 2) {
		nowe[2] = 1;
		wartosc = wartosc - 2;
	}

	if (wartosc >= 1) {
		nowe[3] = 1;
		wartosc = wartosc - 1;
	}
	
	cout << "4 nowe bity to: ";
	for (int j = 0; j < 4; j++) {
		cout << nowe[j];
	}

	cout << endl;
	
}


void permutacja_function(bool*klucz, int permut[32], bool*po_permutacji){
	for (int i = 0; i < 32; i++) {
		po_permutacji[i] = klucz[(permut[i]-1)];
	}
	cout << "Klucz po permutacji: " << endl;
	for (int i = 0; i < 32; i++) {
		cout << po_permutacji[i];

	}
	cout << endl;
}

void xorowanie(bool*tablica_1, bool*tablica_2, bool*tablica_wynik) {
	for (int i = 0; i < 32; i++) {
		tablica_wynik[i] = (tablica_1[i] xor tablica_2[i]);

	}
}


void szesc_bitow_dla_S5(bool*tablica_in , bool*tablica_out) {
	cout << "Wartosc 6-bitowego klucza dla S-boxa nr 5:" << endl;
	for (int i = 24; i < 30; i++) {
		tablica_out[i - 24] = tablica_in[i];
		cout << tablica_in[i];
	}
}










int main() {
	// deklaracja S5Box
	cout << "Edycja ciagu bitow mozliwa tylko edytujac kod" << endl<<endl;

	int permutacja[32] = {16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};
	bool key[32] = { 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 1,1 };
	bool * wsk_key=key;
	bool key_after[32];
	bool* wsk_key_after=key_after;

	bool tab_in[48] = { 0,0,0,0,0,0, 0,0,0,0,0,0, 0,0,0,0,0,0, 0,0,0,0,0,0,    1,0,1,1,0,0,    0,0,0,0,0,0, 0,0,0,0,0,0, 0,0,0,0,0,0 };
	bool tab_out[6];

	bool*tab_ptr_i = tab_in;
	bool*tab_ptr_o = tab_out;




	int S5box[4][16] = { 2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3 };
	bool tab[6] = { 0,1,0,1,0,0 };
	bool tab_nowa[4] = { 0,0,0,0 };
	bool*nowe_bity = tab_nowa;
	bool* wsk=tab;
	S5_box_function(wsk, S5box, nowe_bity);
	
	system("pause");
	cout << endl;

	for (int i = 0; i < 32; i++) {
		key_after[i] = 0;
	}

	permutacja_function(wsk_key, permutacja , wsk_key_after);
	system("pause");
	cout << endl;

		
	bool tablica1[32] = {0,0,0,1,1,0,1,0,1,1, 0,0,1,1,1,1,0,1,1,0, 0,0,0,1,1,0,1,0,1,1, 1,0 };
	bool tablica2[32] = {1,1,1,0,0,1,0,1,0,0, 1,1,0,0,0,0,1,0,0,1, 1,1,1,0,0,1,0,1,0,0, 1,0 };
	bool tablica3[32] = {};

	bool*tab1 = tablica1;
	bool*tab2 = tablica2;
	bool*tab3 = tablica3;

	xorowanie(tab1, tab2, tab3);

	cout << "Tablica 32 bitow, wynik funkcji xor dwoch tablic 32 bitowych"<<endl;
	for (int i = 0; i < 32; i++) {
		cout << tab3[i];
	}
	cout << endl;
	system("pause");
	cout << endl;

	szesc_bitow_dla_S5(tab_ptr_i, tab_ptr_o);

	cout << endl;
	system("pause");
	
	

	return 0;

}
