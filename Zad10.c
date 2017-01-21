//Tomasz Kontek 160553
/*10. Na poniższym rysunku pokazane są dwa formaty
32 - bitowych liczb stałoprzecinkowych bez znaku
używane w programie.
 
<31> |2^23|2^22|(...)|2^(-7)|2^(-8)| <0>      //reprezentować ten format będzie zmienna x
<31> |2^24|2^23|(...)|2^(-6)|2^(-7)| <0>      //reprezontować ten format będzie zmienna y
Zakładając, że w rejestrze ESI znajduje się liczba
zakodowana wg pierwszego formatu(najmniej znaczący bit ma wagę 2?8),
a w rejestrze EDI liczba zakodowana wg drugiego formatu(najmniej znaczącybit ma wagę 2?7),
napisać fragmentu, który porówna
obie liczby.Jeśli liczba w rejestrze ESI jest większa
od liczby w rejestrze EDI, to do CF należy wpisać 1, w
przeciwnym razie 0 (rozkazy STC / CLC).*/
#include <stdio.h>

extern int funkcja(unsigned int x,unsigned int y);

int main() {
	int x = 0x00002020;
	int y = 0x00001010; //Przy podanych w treści zadania formatach te liczby są równe
	printf("Funkcja zwraca 0 gdy x>y a 1 gdy x<=y \n");
	printf("Dla liczb równych wynik wynosi = %d\n", funkcja(x, y));
	x = 0x00003010; // x>y przy podanych formatach
	y = 0x00001010;
	printf("Dla x większego wynik wynosi = %d\n", funkcja(x, y));
	x = 0x00003010; // x<y przy podanych formatach
	y = 0x02001010;
	printf("Dla x mniejszego wynik wynosi = %d\n", funkcja(x, y));
	x = 0x00003010; // x<y przy podanych formatach, i bit nr 31 dla y = 1
	y = 0x82001010;
	printf("Dla x mniejszego wynik wynosi,( i bit nr 31 liczby y = 1 ) wtedy wynik = %d\n", funkcja(x, y));
	getchar();
	return 0;
}
