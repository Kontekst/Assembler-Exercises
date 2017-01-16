//Tomasz Kontek 160553
/*4. Poni¿ej podano fragment programu w jêzyku C.
int pomiary[7], * wsk;
- - - - - - - - - - - - - - -
wsk = szukaj_elem_min(pomiary, 7);
printf("\nElement minimalny = %d\n",
 * wsk);
Napisaæ podprogram w asemblerze przystosowany do

//Tomasz Kontek 160553
/*2. Funkcja biblioteczna jêzyka C o prototypie
void * malloc(unsigned int k);
przydziela k - bajtowy obszar pamiêci i zwraca adres
przydzielonego obszaru.Jeœli wymagany obszar nie
mo¿e byæ przydzielony, to funkcja zwraca wartoœæ 0.
Napisaæ podprogram w asemblerze, przystosowany do
wywo³ywania z poziomu jêzyka C — prototyp tego
podprogramu ma postaæ :
int * kopia_tablicy(int tabl[],
unsigned int n);
Podprogram kopia_tablicy tworzy now¹ tablicê
o rozmiarach identycznych z oryginaln¹ i zwraca adres
nowej tablicy(albo 0, jeœli tablicy nie mo¿na by³o
utworzyæ).
Do nowej tablicy nale¿y skopiowaæ wszystkie
elementy tablicy oryginalnej o wartoœciach bêd¹cych
liczbami parzystymi.Pozosta³e elementy nowej tablicy
wype³niæ zerami.
Wskazówki:
1. Now¹ tablicê nale¿y utworzyæ poprzez
przydzielenie odpowiedniego obszaru pamiêci za
pomoc¹ funkcji malloc.
2. Sprawdzenie czy liczba jest parzysta naj³atwiej
wykonaæ poprzez odczytanie najm³odszego bitu
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
		printf("B³ad nie uda³o siê zaalokowaæ pamiêci\n");
	}
	getchar();
	return 0;
}