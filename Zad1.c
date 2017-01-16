//Tomasz Kontek 160553
/*
1. Poniżej podano fragment programu w języku C.
int a, b, *wsk, wynik;
wsk = &b;
a = 21; b = 25;
wynik = roznica(&a, &wsk);

Napisać podprogram w asemblerze przystosowany do
wywoływania z poziomu języka C, którego prototyp ma
postać :

int roznica(int * odjemna,
	int ** odjemnik);

Podprogram ten powinien obliczyć różnicę dwóch liczb
całkowitych ze znakiem w kodzie U2.
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
