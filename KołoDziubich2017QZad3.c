//Tomasz Kontek 160553
//Treœæ zadania w pliku Ko³oNr2Dziubich2017.jpg
#include <stdio.h>

extern float* XYZ2R(float *  tablCIEXYZ, int n);

int main() {
	float * wsk;
	float tab[12] = {
		1.0, 2.0, 3.0,
		1.5, 2.5, 3.5,
		4.5, 2.5, 5.0,
		0.5, 10.0, 0.75
	};

	int rozmiar = sizeof(tab) / sizeof(tab[0]);
	for (int i = 0; i < (rozmiar / 3); i++) {
		printf("%f ||| %f ||| %f \n", tab[3 * i], tab[3 * i + 1], tab[3 * i + 2]);
	}printf("\n\n");
	wsk = tab;

	wsk = XYZ2R(wsk, (rozmiar / 3));

	for (int i = 0; i < (rozmiar / 3); i++) {
		printf("%f ||| %f ||| %f \n", wsk[3 * i], wsk[3 * i + 1], wsk[3 * i + 2]);
	}printf("\n\n");

	getchar();
	return 0;
}
