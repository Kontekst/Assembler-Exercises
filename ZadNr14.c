//Tomasz Kontek 160553
/*14. W pamiêci komputera, pocz¹wszy od adresu
podanego w rejestrze ESI znajduje siê 32-bitowa
liczba zmiennoprzecinkowa w formacie float. Napisaæ
fragment programu, który przekszta³ci tê liczbê na 64-
bitowy format double i uzyskany rezultat wpisze do
pamiêci pocz¹wszy od adresu podanego w rejestrze
EDI. W omawianym fragmencie nie mo¿na u¿ywaæ
rozkazów koprocesora arytmetycznego. 
*/
#include <stdio.h>
extern double* funkcja(float*);

int main() {
	float liczba = -6.000002;
	double* ptr =funkcja(&liczba);
	printf("%f \n ", *ptr);
	getchar();
	return 0;
}

//double liczba2 = -2146.002141402;
//double* ptr2 = &liczba2;
//printf("%f\n", *ptr2);
