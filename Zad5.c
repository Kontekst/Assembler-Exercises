//Tomasz Kontek 160553
/*5. Podprogram, przystosowany do wywoływania z
poziomu języka C, o prototypie :
void szyfruj(char * tekst);
szyfruje każdy bajt obszaru tekst poprzez
wykonanie operacji XOR, której drugim argumentem
jest ciąg 8 bitów.Ciąg ma inną postać dla każdego
bajtu i stanowi 8 najmłodszych bitów 32 - bitowej
liczby losowej.Pierwsza liczba losowa ma wartość
52525252H, a następne obliczane są w poniższy
sposób :
a.wyznacza się sumę modulo dwa bitów nr 30 i 31,
b.przesuwa się całą liczbę 32 - bitową o jedną
pozycję w lewo,
c.na bit nr 0 liczby wprowadza się wcześniej
obliczoną sumę modulo dwa.
Napisać kod podprogramu szyfruj w asemblerze.*/

#include <stdio.h>

extern void szyfruj(char * tekst);

int main() {
	char wsk[] = "Tekst przykładowy";
	printf("%s\n", wsk);
	szyfruj(wsk);
	printf("%s", wsk);
	getchar();
	return 0;
}
