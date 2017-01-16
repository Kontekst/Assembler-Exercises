;W treœci zadania nie ma napisane czy zwróciæ adres pierwszego czy ostatniego elementu minimalnego w przypadku gdy jest ich kilka, podprogram ten zwraca ostatni adres elementu najmniejszego
.686
.model flat

public _szukaj_elem_min
.code

_szukaj_elem_min PROC
; Obowi¹zkowe pushowanie rejestów ebx,ebp,esi,edi aby je przywróciæ przed powrotem do programu g³ównego
push ebx 
push ebp
push esi
push edi

mov ebp,esp

mov esi, [ ebp + 20 ] ; ESI = Adres tablicy
mov ecx, [ ebp + 24 ] ; ECX = Iloœæ elementów
mov ebx,4 ; EBX = 4, bêdzie wspó³czynnikiem zwiêkszanym o 4 aby dostaæ siê do kolejnych elemntów tablicy
mov edi,[esi] ; EDI = pierwszy element, EAX bêdzie przechowywa³o tak¿e aktualnie najmniejszy element tablicy 
mov eax,esi ; EAX = Adres najmniejszego elementu

poczatekPetli:
mov edx,[esi + ebx] ; EDX = Kolejny element
cmp edx,edi ; Jeœli EDX > EAX to idziemy do kolejnego obiegu pêtli
jg nieMaPodmiany

mov edi, edx ; Przepisanie najmniejszego elementu do edi
mov eax, ebx ; Adres tego elementu to esi + ebx, a wiêc adres elementu pocz¹tkowego tablicy + n*4 ( Int ma zazwyczaj 4 bajty ) 
add eax, esi ; Przepisanie adresu najmniejszego elemntu do EAX 

nieMaPodmiany:

dec ecx ; Zmniejszenie iloœci obiegów o 1 
add ebx,4 ; EBX zwiêkszony aby odnieœæ siê do nastêpnego elementu
cmp ecx,1 ; Jeœli ECX = 1 koniec pêtli, poniewa¿ w pierwszym obiegu pobieramy a¿ 2 elementy z tablicy do porównañ
jne poczatekPetli


; Obowi¹zkowe przywrócenie wartoœci rejestrów przed wyjœciem z podprogramu 
pop edi
pop esi
pop ebp
pop ebx
ret
_szukaj_elem_min ENDP
END