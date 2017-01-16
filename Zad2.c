//Tomasz Kontek 160553
/*4. Poni�ej podano fragment programu w j�zyku C.
int pomiary[7], * wsk;
- - - - - - - - - - - - - - -
wsk = szukaj_elem_min(pomiary, 7);
printf("\nElement minimalny = %d\n",
 * wsk);
Napisa� podprogram w asemblerze przystosowany do

//Tomasz Kontek 160553
/*2. Funkcja biblioteczna j�zyka C o prototypie
void * malloc(unsigned int k);
przydziela k - bajtowy obszar pami�ci i zwraca adres
przydzielonego obszaru.Je�li wymagany obszar nie
mo�e by� przydzielony, to funkcja zwraca warto�� 0.
Napisa� podprogram w asemblerze, przystosowany do
wywo�ywania z poziomu j�zyka C � prototyp tego
podprogramu ma posta� :
int * kopia_tablicy(int tabl[],
unsigned int n);
Podprogram kopia_tablicy tworzy now� tablic�
o rozmiarach identycznych z oryginaln� i zwraca adres
nowej tablicy(albo 0, je�li tablicy nie mo�na by�o
utworzy�).
Do nowej tablicy nale�y skopiowa� wszystkie
elementy tablicy oryginalnej o warto�ciach b�d�cych
liczbami parzystymi.Pozosta�e elementy nowej tablicy
wype�ni� zerami.
Wskaz�wki:
1. Now� tablic� nale�y utworzy� poprzez
przydzielenie odpowiedniego obszaru pami�ci za
pomoc� funkcji malloc.
2. Sprawdzenie czy liczba jest parzysta naj�atwiej
wykona� poprzez odczytanie najm�odszego bitu
liczby(bit nr 0).*/



#include <stdio.h>

extern int * kopia_tablicy(int tabl[], unsigned int n);

int main() {
	int tablicaPoczatkowa[] = { 1,-14,13,64,2,547,3,44,68,12,14 };
	int n = sizeof(tablicaPoczatkowa) / sizeof(tablicaPoczatkowa[0]);
	int * wskaznikNaKopieTablicy;

	wskaznikNaKopieTablicy = kopia_tablicy(tablicaPoczatkowa, n);
	if (wskaznikNaKopieTablicy != 0) {
		printf("Adres nowej tablicy to %d \n", wskaznikNaKopieTablicy);

		for (int i = 0; i < n; i++) {
			printf("%d ", wskaznikNaKopieTablicy[i]);
		}
		printf("\n");
	}
	else {
		printf("B�ad nie uda�o si� zaalokowa� pami�ci\n");
	}
	getchar();
	return 0;
}