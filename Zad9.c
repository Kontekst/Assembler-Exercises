//Tomasz Kontek 160553
/*9. W programie zdefiniowano format 32-bitowych
liczb mieszanych w kodzie U2 przyjmujšc, że
najmniej znaczšcy bit ma wagę 2^(-7) // (kolejne 2^ (-6) itd. aż do 2^23) a najstarszy bit  to bit znaku 
Przyjmujšc, że liczba w podanym formacie znajduje
się w rejestrze EDX, napisać fragment programu,
który zaokršgli tę liczbę do najbliższej liczby
całkowitej. Wynik należy pozostawić również w
rejestrze EDX w podanym formacie.
Wskazówka: zbadać stan bitu o wadze 2-1. 
*/
#include <stdio.h>

extern int funkcja(int a);

int main() {
	int wynik;
	int parametr = 0x00000200;// Kiedy trzecia cyfra od prawej = 4/5/6/7 lub C/D/E/F to zaokršglam do góry
	wynik=funkcja(parametr);
	getchar();

	printf("0x0200 wynik to %d\n", wynik);

	parametr = 0x00000000;
	wynik = funkcja(parametr);
	printf("0x0000 wynik to %d\n", wynik);

	parametr = 0x0000004F;
	wynik = funkcja(parametr);
	printf("0x004F wynik to %d\n", wynik);

	parametr = 0x0000025C; 
        wynik = funkcja(parametr);
	printf("0x025C wynik to %d\n", wynik);

	parametr = 0x000002D0;
	wynik = funkcja(parametr);
	printf("0x02D0 wynik to %d\n", wynik);

	parametr = 0xA0BC;
	wynik = funkcja(parametr);
	printf("0xA0BC wynik to %d\n", wynik);

	getchar();
	return 0;
}
