//Nie mam pewno�ci czy szyfruje dok�adnie z celem zadania

//Tomasz Kontek 160553
/*5. Podprogram, przystosowany do wywo�ywania z
poziomu j�zyka C, o prototypie :
void szyfruj(char * tekst);
szyfruje ka�dy bajt obszaru tekst poprzez
wykonanie operacji XOR, kt�rej drugim argumentem
jest ci�g 8 bit�w.Ci�g ma inn� posta� dla ka�dego
bajtu i stanowi 8 najm�odszych bit�w 32 - bitowej
liczby losowej.Pierwsza liczba losowa ma warto��
52525252H, a nast�pne obliczane s� w poni�szy
spos�b :
a.wyznacza si� sum� modulo dwa bit�w nr 30 i 31,
b.przesuwa si� ca�� liczb� 32 - bitow� o jedn�
pozycj� w lewo,
c.na bit nr 0 liczby wprowadza si� wcze�niej
obliczon� sum� modulo dwa.
Napisa� kod podprogramu szyfruj w asemblerze.*/
#include   <stdio.h >

#include <stdio.h>

extern void szyfruj(char * tekst);

int main() {
	char wsk[] = "Tekst przyk�adowy";
	printf("%s\n", wsk);
	szyfruj(wsk);
	printf("%s", wsk);
	getchar();
	return 0;
}