//Tomasz Kontek 160553
/*14. W pami�ci komputera, pocz�wszy od adresu
podanego w rejestrze ESI znajduje si� 32-bitowa
liczba zmiennoprzecinkowa w formacie float. Napisa�
fragment programu, kt�ry przekszta�ci t� liczb� na 64-
bitowy format double i uzyskany rezultat wpisze do
pami�ci pocz�wszy od adresu podanego w rejestrze
EDI. W omawianym fragmencie nie mo�na u�ywa�
rozkaz�w koprocesora arytmetycznego. 
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
