//Tomasz Kontek 160553
//Treœæ zadania w pliku Ko³oNr2Dziubich2017.jpg
#include <stdio.h>

extern double ciag(unsigned int * x);

int main() {
	unsigned int* wsk;
	int parametr = 1;
	wsk = &parametr;
	double wynik = ciag(*wsk);
	printf("%f\n", wynik);

	parametr = 2;
	wynik = ciag(*wsk);
	printf("%f\n", wynik);

	parametr = 3;
	wynik = ciag(*wsk);
	printf("%f\n", wynik);

	parametr = 4;
	wynik = ciag(*wsk);
	printf("%f\n", wynik);

	getchar();
	return 0;
}