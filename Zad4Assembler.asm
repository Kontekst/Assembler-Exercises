;W tre�ci zadania nie ma napisane czy zwr�ci� adres pierwszego czy ostatniego elementu minimalnego w przypadku gdy jest ich kilka, podprogram ten zwraca ostatni adres elementu najmniejszego
.686
.model flat

public _szukaj_elem_min
.code

_szukaj_elem_min PROC
; Obowi�zkowe pushowanie rejest�w ebx,ebp,esi,edi aby je przywr�ci� przed powrotem do programu g��wnego
push ebx 
push ebp
push esi
push edi

mov ebp,esp

mov esi, [ ebp + 20 ] ; ESI = Adres tablicy
mov ecx, [ ebp + 24 ] ; ECX = Ilo�� element�w
mov ebx,4 ; EBX = 4, b�dzie wsp�czynnikiem zwi�kszanym o 4 aby dosta� si� do kolejnych elemnt�w tablicy
mov edi,[esi] ; EDI = pierwszy element, EAX b�dzie przechowywa�o tak�e aktualnie najmniejszy element tablicy 
mov eax,esi ; EAX = Adres najmniejszego elementu

poczatekPetli:
mov edx,[esi + ebx] ; EDX = Kolejny element
cmp edx,edi ; Je�li EDX > EAX to idziemy do kolejnego obiegu p�tli
jg nieMaPodmiany

mov edi, edx ; Przepisanie najmniejszego elementu do edi
mov eax, ebx ; Adres tego elementu to esi + ebx, a wi�c adres elementu pocz�tkowego tablicy + n*4 ( Int ma zazwyczaj 4 bajty ) 
add eax, esi ; Przepisanie adresu najmniejszego elemntu do EAX 

nieMaPodmiany:

dec ecx ; Zmniejszenie ilo�ci obieg�w o 1 
add ebx,4 ; EBX zwi�kszony aby odnie�� si� do nast�pnego elementu
cmp ecx,1 ; Je�li ECX = 1 koniec p�tli, poniewa� w pierwszym obiegu pobieramy a� 2 elementy z tablicy do por�wna�
jne poczatekPetli


; Obowi�zkowe przywr�cenie warto�ci rejestr�w przed wyj�ciem z podprogramu 
pop edi
pop esi
pop ebp
pop ebx
ret
_szukaj_elem_min ENDP
END