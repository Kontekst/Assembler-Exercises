//Tomasz Kontek 160553
/*4. Poni�ej podano fragment programu w j�zyku C.
int pomiary[7], * wsk;
- - - - - - - - - - - - - - -
wsk = szukaj_elem_min(pomiary, 7);
printf("\nElement minimalny = %d\n",
 * wsk);
Napisa� podprogram w asemblerze przystosowany do
wywo�ywania z poziomu j�zyka C, kt�rego prototyp
ma posta�:
int * szukaj_elem_min (
 int tablica[ ], int n);
Podprogram ten powinien wyznaczy� najmniejszy
element tablicy i zwr�ci� adres (wska�nik) tego
elementu. Liczb� element�w tablicy okre�la drugi
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