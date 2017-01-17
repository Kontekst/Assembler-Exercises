//Tomasz Kontek 160553
/*2. Funkcja biblioteczna języka C o prototypie
void * malloc(unsigned int k);
przydziela k - bajtowy obszar pamięci i zwraca adres
przydzielonego obszaru.Jeśli wymagany obszar nie
może być przydzielony, to funkcja zwraca wartość 0.
Napisać podprogram w asemblerze, przystosowany do
wywoływania z poziomu języka C — prototyp tego
podprogramu ma postać :
int * kopia_tablicy(int tabl[],
unsigned int n);
Podprogram kopia_tablicy tworzy nową tablicę
o rozmiarach identycznych z oryginalną i zwraca adres
nowej tablicy(albo 0, jeśli tablicy nie można było
utworzyć).
Do nowej tablicy należy skopiować wszystkie
elementy tablicy oryginalnej o wartościach będących
liczbami parzystymi.Pozostałe elementy nowej tablicy
wypełnić zerami.
Wskazówki:
1. Nową tablicę należy utworzyć poprzez
przydzielenie odpowiedniego obszaru pamięci za
pomocą funkcji malloc.
2. Sprawdzenie czy liczba jest parzysta najłatwiej
wykonać poprzez odczytanie najmłodszego bitu
liczby(bit nr 0).
*/



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
		printf("Bład nie udało się zaalokować pamięci\n");
	}
	getchar();
	return 0;
}
