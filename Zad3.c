//Tomasz Kontek 160553
/*3. Podprogram, przystosowany do wywo�ywania z
poziomu j�zyka C, o prototypie:
char * komunikat (char * tekst);
rezerwuje obszar pami�ci (za pomoc� funkcji
malloc) i wpisuje do niego tekst wskazany przez
parametr tekst, bezpo�rednio za kt�rym zostaje
dopisany �a�cuch znak�w "B��d.". Podprogram
zwraca adres przydzielonego obszaru. Napisa� kod
asemblerowy tego podprogramu.
Wskaz�wka: �a�cuch znak�w ko�czy si� bajtem o
warto�ci 0*/

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