//Tomasz Kontek 160553
/*
1. Poni�ej podano fragment programu w j�zyku C.
int a, b, *wsk, wynik;
wsk = &b;
a = 21; b = 25;
wynik = roznica(&a, &wsk);

Napisa� podprogram w asemblerze przystosowany do
wywo�ywania z poziomu j�zyka C, kt�rego prototyp ma
posta� :

int roznica(int * odjemna,
	int ** odjemnik);

Podprogram ten powinien obliczy� r�nic� dw�ch liczb
ca�kowitych ze znakiem w kodzie U2.
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