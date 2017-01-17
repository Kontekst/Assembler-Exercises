//Nie mam pewnoœci czy szyfruje dok³adnie z celem zadania

//Tomasz Kontek 160553
/*5. Podprogram, przystosowany do wywo³ywania z
poziomu jêzyka C, o prototypie :
void szyfruj(char * tekst);
szyfruje ka¿dy bajt obszaru tekst poprzez
wykonanie operacji XOR, której drugim argumentem
jest ci¹g 8 bitów.Ci¹g ma inn¹ postaæ dla ka¿dego
bajtu i stanowi 8 najm³odszych bitów 32 - bitowej
liczby losowej.Pierwsza liczba losowa ma wartoœæ
52525252H, a nastêpne obliczane s¹ w poni¿szy
sposób :
a.wyznacza siê sumê modulo dwa bitów nr 30 i 31,
b.przesuwa siê ca³¹ liczbê 32 - bitow¹ o jedn¹
pozycjê w lewo,
c.na bit nr 0 liczby wprowadza siê wczeœniej
obliczon¹ sumê modulo dwa.
Napisaæ kod podprogramu szyfruj w asemblerze.*/
#include   <stdio.h >

#include <stdio.h>

extern void szyfruj(char * tekst);

int main() {
	char wsk[] = "Tekst przyk³adowy";
	printf("%s\n", wsk);
	szyfruj(wsk);
	printf("%s", wsk);
	getchar();
	return 0;
}