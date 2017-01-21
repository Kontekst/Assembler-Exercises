//Tomasz Kontek 160553
/*6. 6. Napisaæ podprogram w asemblerze obliczaj¹cy
wartoœæ funkcji kwadrat metod¹ rekurencyjn¹
korzystaj¹c z zale¿noœci:
a^2 = (a – 2)^2 + 4?a – 4 dla a > 1
a^2 = 1 dla a = 1
a^2 = 0 dla a = 0
przy czym argument a jest liczb¹ ca³kowit¹ 32-bitow¹
zawart¹ w przedziale <1, 65535>.
Podprogram powinien byæ przystosowany do
wywo³ywania z poziomu jêzyka C, a jego prototyp ma
postaæ:
unsigned int kwadrat (unsigned int a); */

#include <stdio.h>

unsigned int kwadrat(unsigned int a);

int main() {
	unsigned int zmienna = 12;
	printf("Kwadrat(0) = %d\n", kwadrat(0));
	printf("Kwadrat(1) = %d\n", kwadrat(1));
	printf("Kwadrat(2) = %d\n", kwadrat(2));
	printf("Kwadrat(3) = %d\n", kwadrat(3));
	printf("Kwadrat(4) = %d\n", kwadrat(4));
	printf("Kwadrat(5) = %d\n", kwadrat(5));
	printf("Kwadrat(6) = %d\n", kwadrat(6));
	printf("Kwadrat(7) = %d\n", kwadrat(7));
	printf("Kwadrat(10) = %d\n", kwadrat(10));
	printf("Kwadrat(20) = %d\n", kwadrat(20));
	getchar();
	return 0;
}