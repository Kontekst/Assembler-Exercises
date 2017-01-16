//Tomasz Kontek 160553
/*4. Poni¿ej podano fragment programu w jêzyku C.
int pomiary[7], * wsk;
- - - - - - - - - - - - - - -
wsk = szukaj_elem_min(pomiary, 7);
printf("\nElement minimalny = %d\n",
 * wsk);
Napisaæ podprogram w asemblerze przystosowany do
wywo³ywania z poziomu jêzyka C, którego prototyp
ma postaæ:
int * szukaj_elem_min (
 int tablica[ ], int n);
Podprogram ten powinien wyznaczyæ najmniejszy
element tablicy i zwróciæ adres (wskaŸnik) tego
elementu. Liczbê elementów tablicy okreœla drugi
parametr funkcji. 
*/

#include <stdio.h>

extern int * szukaj_elem_min(int tablica[], int n);

int main(){
int *wsk;
int pomiary[] = { 1,5,2,5,8,2,1 };
wsk = szukaj_elem_min(pomiary, 7 );
printf("Element minimalny = %d\n",*wsk);
getchar();
return 0;
}