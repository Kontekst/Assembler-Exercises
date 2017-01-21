//Tomasz Kontek 160553
/*10. Na poni�szym rysunku pokazane s� dwa formaty
32 - bitowych liczb sta�oprzecinkowych bez znaku
u�ywane w programie.
 
<31> |2^23|2^22|(...)|2^(-7)|2^(-8)| <0>      //reprezentowa� ten format b�dzie zmienna x
<31> |2^24|2^23|(...)|2^(-6)|2^(-7)| <0>      //reprezontowa� ten format b�dzie zmienna y
Zak�adaj�c, �e w rejestrze ESI znajduje si� liczba
zakodowana wg pierwszego formatu(najmniej znacz�cy bit ma wag� 2?8),
a w rejestrze EDI liczba zakodowana wg drugiego formatu(najmniej znacz�cybit ma wag� 2?7),
napisa� fragmentu, kt�ry por�wna
obie liczby.Je�li liczba w rejestrze ESI jest wi�ksza
od liczby w rejestrze EDI, to do CF nale�y wpisa� 1, w
przeciwnym razie 0 (rozkazy STC / CLC).*/#include <stdio.h>

extern int funkcja(unsigned int x,unsigned int y);

int main() {
	int x = 0x00002020;
	int y = 0x00001010; //Przy podanych w tre�ci zadania formatach te liczby s� r�wne
	printf("Funkcja zwraca 0 gdy x>y a 1 gdy x<=y \n");
	printf("Dla liczb r�wnych wynik wynosi = %d\n", funkcja(x, y));
	x = 0x00003010; // x>y przy podanych formatach
	y = 0x00001010;
	printf("Dla x wi�kszego wynik wynosi = %d\n", funkcja(x, y));
	x = 0x00003010; // x<y przy podanych formatach
	y = 0x02001010;
	printf("Dla x mniejszego wynik wynosi = %d\n", funkcja(x, y));
	x = 0x00003010; // x<y przy podanych formatach, i bit nr 31 dla y = 1
	y = 0x82001010;
	printf("Dla x mniejszego wynik wynosi,( i bit nr 31 liczby y = 1 ) wtedy wynik = %d\n", funkcja(x, y));
	getchar();
	return 0;
}