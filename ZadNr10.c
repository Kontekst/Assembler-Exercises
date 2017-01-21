//Tomasz Kontek 160553
/*10. Na poni¿szym rysunku pokazane s¹ dwa formaty
32 - bitowych liczb sta³oprzecinkowych bez znaku
u¿ywane w programie.
 
<31> |2^23|2^22|(...)|2^(-7)|2^(-8)| <0>      //reprezentowaæ ten format bêdzie zmienna x
<31> |2^24|2^23|(...)|2^(-6)|2^(-7)| <0>      //reprezontowaæ ten format bêdzie zmienna y
Zak³adaj¹c, ¿e w rejestrze ESI znajduje siê liczba
zakodowana wg pierwszego formatu(najmniej znacz¹cy bit ma wagê 2?8),
a w rejestrze EDI liczba zakodowana wg drugiego formatu(najmniej znacz¹cybit ma wagê 2?7),
napisaæ fragmentu, który porówna
obie liczby.Jeœli liczba w rejestrze ESI jest wiêksza
od liczby w rejestrze EDI, to do CF nale¿y wpisaæ 1, w
przeciwnym razie 0 (rozkazy STC / CLC).*/#include <stdio.h>

extern int funkcja(unsigned int x,unsigned int y);

int main() {
	int x = 0x00002020;
	int y = 0x00001010; //Przy podanych w treœci zadania formatach te liczby s¹ równe
	printf("Funkcja zwraca 0 gdy x>y a 1 gdy x<=y \n");
	printf("Dla liczb równych wynik wynosi = %d\n", funkcja(x, y));
	x = 0x00003010; // x>y przy podanych formatach
	y = 0x00001010;
	printf("Dla x wiêkszego wynik wynosi = %d\n", funkcja(x, y));
	x = 0x00003010; // x<y przy podanych formatach
	y = 0x02001010;
	printf("Dla x mniejszego wynik wynosi = %d\n", funkcja(x, y));
	x = 0x00003010; // x<y przy podanych formatach, i bit nr 31 dla y = 1
	y = 0x82001010;
	printf("Dla x mniejszego wynik wynosi,( i bit nr 31 liczby y = 1 ) wtedy wynik = %d\n", funkcja(x, y));
	getchar();
	return 0;
}