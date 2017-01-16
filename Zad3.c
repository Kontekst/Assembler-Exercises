//Tomasz Kontek 160553
/*3. Podprogram, przystosowany do wywo³ywania z
poziomu jêzyka C, o prototypie:
char * komunikat (char * tekst);
rezerwuje obszar pamiêci (za pomoc¹ funkcji
malloc) i wpisuje do niego tekst wskazany przez
parametr tekst, bezpoœrednio za którym zostaje
dopisany ³añcuch znaków "B³¹d.". Podprogram
zwraca adres przydzielonego obszaru. Napisaæ kod
asemblerowy tego podprogramu.
Wskazówka: ³añcuch znaków koñczy siê bajtem o
wartoœci 0*/

#include <stdio.h>

extern char * komunikat(char * tekst);

int main() {
	char * wsk= "Alfa beta ";
	printf("%s\n", wsk);
	char * nowyWsk = komunikat(wsk);
	printf("%s", nowyWsk);
	getchar();
	return 0;
}