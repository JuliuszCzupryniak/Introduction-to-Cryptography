#include <iostream>


using namespace std;





bool tmp;

//===============================================================================================================================================================================================

void feedback_R1(bool*tablica, bool bit) {
	bool wynik = tablica[18] xor tablica[17] xor tablica[16] xor tablica[13] xor bit;
	for (int it = 18; it > 0; it--) {
		tablica[it] = tablica[it - 1];
	}
	tablica[0] = wynik;
}

void feedback_R2(bool*tablica, bool bit) {
	bool wynik = tablica[21] xor tablica[20] xor bit;
	for (int it = 21; it > 0; it--) {
		tablica[it] = tablica[it - 1];
	}
	tablica[0] = wynik;
}

void feedback_R3(bool*tablica, bool bit) {
	bool wynik = tablica[22] xor tablica[21] xor tablica[20] xor tablica[7] xor bit;
	for (int it = 22; it > 0; it--) {
		tablica[it] = tablica[it - 1];
	}
	tablica[0] = wynik;
}

//=================================================================================================================================================================================================

void feedback_R1(bool*tablica) {
	bool wynik = tablica[18] xor tablica[17] xor tablica[16] xor tablica[13];
	for (int it = 18; it > 0; it--) {
		tablica[it] = tablica[it - 1];
	}
	tablica[0] = wynik;
}

void feedback_R2(bool*tablica) {
	bool wynik = tablica[21] xor tablica[20];
	for (int it = 21; it > 0; it--) {
		tablica[it] = tablica[it - 1];
	}
	tablica[0] = wynik;
}

void feedback_R3(bool*tablica) {
	bool wynik = tablica[22] xor tablica[21] xor tablica[20] xor tablica[7];
	for (int it = 22; it > 0; it--) {
		tablica[it] = tablica[it - 1];
	}
	tablica[0] = wynik;
}

//=================================================================================================================================================================================================








int main() {
	//zadeklarowanie trzech rejestrów Linear Feedback Shift Register
	bool R1[19];
	bool R2[22];
	bool R3[23];

	//ustawienie wartości rejestrów na ciąg zer
	for (int iterator = 0; iterator < 19; iterator++) {
		R1[iterator] = false;
	}
	for (int iterator = 0; iterator < 22; iterator++) {
		R2[iterator] = false;
	}
	for (int iterator = 0; iterator < 23; iterator++) {
		R3[iterator] = false;
	}
	//Klucz prywatny
	bool klucz[64] = { 0,1,0,0,1,1,1,0,0,0,1,0,1,1,1,1,0,1,0,0,1,1,0,1,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,1,0,1,1,1,0,0,0,1,0,0,0,1,0,1,1,0,0,1,1,1,0,1,0 };

	//Ramka jawna
	bool ramka[22] = { 1,1,1,0,1,0,1,0,1,1,0,0,1,1,1,1,0,0,1,0,1,1 };


	//operacje XOR w wielomianach rejestrów z kluczem prywatnym
	
	bool * wsk1=R1;
	bool * wsk2=R2;
	bool * wsk3=R3;

	for (int i = 0; i < 64; i++) {
		feedback_R1(wsk1, klucz[i]);
		feedback_R2(wsk2, klucz[i]);
		feedback_R3(wsk3, klucz[i]);
	}
	
	
	
	
//--------------------------------------------------------	
	cout << "Po 64 taktach, Stan rejestru LFSR1: ";;
	for (int i = 0; i < 19; i++) {
		cout << R1[i];
	}
	cout << endl;
//--------------------------------------------------------
	cout << "Po 64 taktach, Stan rejestru LFSR2: ";
	for (int i = 0; i < 22; i++) {
		cout << R2[i];
	}
	cout << endl;
//--------------------------------------------------------
	cout << "Po 64 taktach, Stan rejestru LFSR3: ";
	for (int i = 0; i < 23; i++) {
		cout << R3[i];
	}
	cout << endl << endl;
//--------------------------------------------------------
	system("pause");
	
	

	//te same operacje z ramką jawną

	for (int i = 0; i < 22; i++) {
		feedback_R1(wsk1, ramka[i]);
		feedback_R2(wsk2, ramka[i]);
		feedback_R3(wsk3, ramka[i]);
	}
//--------------------------------------------------------
	cout << "Po 22 taktach, Stan rejestru LFSR1: ";;
	for (int i = 0; i < 19; i++) {
		cout << R1[i];
	}
	cout << endl;
//--------------------------------------------------------
	cout << "Po 22 taktach, Stan rejestru LFSR2: ";
	for (int i = 0; i < 22; i++) {
		cout << R2[i];
	}
	cout << endl;
//--------------------------------------------------------
	cout << "Po 22 taktach, Stan rejestru LFSR3: ";
	for (int i = 0; i < 23; i++) {
		cout << R3[i];
	}
	cout << endl<<endl<<endl;
//--------------------------------------------------------
	system("pause");
	

	

	//funkcja taktująca rejestry nieregularnie, sprawdzamy które rejestry mają być "przesunięte" 100 razy, to które rejestry taktujemy jest zgodne z tabelą
	for (int i = 0; i < 100; i++) {
		if (R1[8] == 0 && R2[10] == 0 && R3[10] == 0) {
			feedback_R1(wsk1);
			feedback_R2(wsk2);
			feedback_R3(wsk3);
		}
		else if (R1[8] == 0 && R2[10] == 0 && R3[10] == 1) {
			feedback_R1(wsk1);
			feedback_R2(wsk2);
		}
		else if (R1[8] == 0 && R2[10] == 1 && R3[10] == 0) {
			feedback_R1(wsk1);
			feedback_R3(wsk3);
		}
		else if (R1[8] == 1 && R2[10] == 0 && R3[10] == 0) {
			feedback_R2(wsk2);
			feedback_R3(wsk3);
		}
		else if (R1[8] == 0 && R2[10] == 1 && R3[10] == 1) {
			feedback_R2(wsk2);
			feedback_R3(wsk3);
		}
		else if (R1[8] == 1 && R2[10] == 0 && R3[10] == 1) {
			feedback_R1(wsk1);
			feedback_R3(wsk3);
		}
		else if (R1[8] == 1 && R2[10] == 1 && R3[10] == 0) {
			feedback_R1(wsk1);
			feedback_R2(wsk2);
		}
		else if (R1[8] == 1 && R2[10] == 1 && R3[10] == 1) {
			feedback_R1(wsk1);
			feedback_R2(wsk2);
			feedback_R3(wsk3);
		}
	}

//--------------------------------------------------------
	cout << "Po 100 taktach, Stan rejestru LFSR1: ";;
	for (int i = 0; i < 19; i++) {
		cout << R1[i];
	}
	cout << endl;
//--------------------------------------------------------
	cout << "Po 100 taktach, Stan rejestru LFSR2: ";
	for (int i = 0; i < 22; i++) {
		cout << R2[i];
	}
	cout << endl;
//--------------------------------------------------------
	cout << "Po 100 taktach, Stan rejestru LFSR3: ";
	for (int i = 0; i < 23; i++) {
		cout << R3[i];
	}
	cout << endl;
	system("pause");
//--------------------------------------------------------



//228-krotne taktowanie nieregularne, keystream będzie ciągiem bitów wygenerowanych przy każdej iteracji, bit = XOR ostatnich na prawo bitów z każdego rejestru
	bool keystream[228];

	for (int i = 0; i < 228; i++) {
		if (R1[8] == 0 && R2[10] == 0 && R3[10] == 0) {
			keystream[i] = R1[18] xor R2[21] xor R3[22];
			feedback_R1(wsk1);
			feedback_R2(wsk2);
			feedback_R3(wsk3);                                
		}                                                     
		else if (R1[8] == 0 && R2[10] == 0 && R3[10] == 1) { 
			keystream[i] = R1[18] xor R2[21] xor R3[22];
			feedback_R1(wsk1);
			feedback_R2(wsk2);
		}
		else if (R1[8] == 0 && R2[10] == 1 && R3[10] == 0) {
			keystream[i] = R1[18] xor R2[21] xor R3[22];
			feedback_R1(wsk1);
			feedback_R3(wsk3);
		}
		else if (R1[8] == 1 && R2[10] == 0 && R3[10] == 0) {
			keystream[i] = R1[18] xor R2[21] xor R3[22];
			feedback_R2(wsk2);
			feedback_R3(wsk3);
		}
		else if (R1[8] == 0 && R2[10] == 1 && R3[10] == 1) {
			keystream[i] = R1[18] xor R2[21] xor R3[22];
			feedback_R2(wsk2);
			feedback_R3(wsk3);
		}
		else if (R1[8] == 1 && R2[10] == 0 && R3[10] == 1) {
			keystream[i] = R1[18] xor R2[21] xor R3[22];
			feedback_R1(wsk1);
			feedback_R3(wsk3);
		}
		else if (R1[8] == 1 && R2[10] == 1 && R3[10] == 0) {
			keystream[i] = R1[18] xor R2[21] xor R3[22];
			feedback_R1(wsk1);
			feedback_R2(wsk2);
		}
		else if (R1[8] == 1 && R2[10] == 1 && R3[10] == 1) {
			keystream[i] = R1[18] xor R2[21] xor R3[22];
			feedback_R1(wsk1);
			feedback_R2(wsk2);
			feedback_R3(wsk3);
		}
	}

//---------------------------------------
	cout << "Stan rejestru LFSR1:";;
	for (int i = 0; i < 19; i++) {
		cout << " " << R1[i];
	}
	cout << endl;
//----------------------------------------
	cout << "Stan rejestru LFSR2:";
	for (int i = 0; i < 22; i++) {
		cout << " " << R2[i];
	}
	cout << endl;
//------------------------------------------
	cout << "Stan rejestru LFSR3:";
	for (int i = 0; i < 23; i++) {
		cout << " " << R3[i];
	}
	cout << endl;
//--------------------------------------------

//wyświetlenie wartości keystreamu

	cout << "KEYSTREAM: " <<  endl;
	for (int i = 0; i < 228; i++) {
		cout << keystream[i];
	}
	cout << endl;
	system("pause");
	

	return 0;

}











