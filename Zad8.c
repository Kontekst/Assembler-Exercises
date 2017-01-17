//Tomasz Kontek 160553
/*8. W programie asemblerowym zdefiniowano format
32-bitowych liczb mieszanych bez znaku, przyjmuj¹c,
¿e najmniej znacz¹cy bit ma wagê 2^(-7)
a kolejne maj¹ wagê 2 razy wiêksz¹
Napisaæ fragment programu w asemblerze, który
wpisze 1 do znacznika CF (rozkaz STC) jeœli czêœæ
ca³kowita liczby zawartej w rejestrze EBX jest ró¿na
od zera; w przeciwnym razie CF powinien zostaæ
wyzerowany (rozkaz CLC). */
#include <stdio.h>

extern int funkcja(unsigned int a);
int main() {	unsigned int parametr= 0x0000;	int wynik = funkcja(parametr);	printf("%d\n", wynik);

	parametr = 0x000F;	wynik = funkcja(parametr);	printf("%d\n", wynik);

	parametr = 0x0070;    wynik = funkcja(parametr);	printf("%d\n", wynik);

	parametr = 0x0080;	wynik = funkcja(parametr);	printf("%d\n", wynik);

	parametr = 0xA0BC;	wynik = funkcja(parametr);	printf("%d\n", wynik);

	getchar();
	return 0;
}