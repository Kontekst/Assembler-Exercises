//Tomasz Kontek 160553
/*
1. Poni¿ej podano fragment programu w jêzyku C.
int a, b, *wsk, wynik;
wsk = &b;
a = 21; b = 25;
wynik = roznica(&a, &wsk);

Napisaæ podprogram w asemblerze przystosowany do
wywo³ywania z poziomu jêzyka C, którego prototyp ma
postaæ :

int roznica(int * odjemna,
	int ** odjemnik);

Podprogram ten powinien obliczyæ ró¿nicê dwóch liczb
ca³kowitych ze znakiem w kodzie U2.
*/
#include <stdio.h>

int main() {
	int a, b, *wsk, wynik;
	wsk = &b;
	a = 21; b = 25;
	wynik = roznica(&a, &wsk);
	printf("%d", wynik);
	getchar();
	return 0;
}