.686
.model flat
 
public _funkcja
.data
wynik dq 0.0
.code

_funkcja PROC
push ebp
mov ebp,esp
push ecx
push esi
push edi

mov esi,[ebp + 8] ; ESI = adres argumentu
mov esi,[esi] ; ESI = argument w formacie 'float'
;-------------------------
 ; Procedura przepisania mantysy 
mov eax,esi
and eax, 007FFFFFH ; Do EAX przepisujemy bity mantysy
shr eax,3 ; Usuniêcie 3 bitów które bêd¹ na m³odszych bitach wyniku
mov dword PTR [wynik + 4], eax ; Przepisanie 20 bitów na starsze 32 bity zmiennej 'wynik'

mov eax,esi
and eax, 00000007H
ror eax,3 ; 3 pozosta³e bity mantysy, które przepisujemy do m³odszej czêœci bitów zmiennej wynik, musz¹ byæ po skrajnie lewej stronie 
mov dword PTR [wynik] , eax ; Przepisanie 3 bitów na starsze 32 bity zmiennej 'wynik'
;-------------------------

;-------------------------
bt esi,31 ; Procedura przepisania bitu znaku
jnc liczba_dodatnia
mov eax,dword PTR wynik + 4
add eax, 80000000H
mov dword PTR [wynik + 4], eax
liczba_dodatnia: ; Koniec procedury przepisania bitu znaku
;-------------------------
mov eax,esi
and eax,7F800000H ; Wyodrêbnienie bitów wyk³adnika
rol eax,9
sub eax,7FH ; Wyk³adnik w formacie 'float' jest przesuniêty o 7FH // Przesuniêcie bitowo - mamy 8 bitów 0111 111( czyli 7FH ) i dodaje siê  do niego  wyk³adnik aby uzyskaæ liczbê w formacie 'float'
add eax,3FFH; Wyk³adnik w formacie 'double' musimy przsun¹æ o 3FFH // Przesuniêcie bitowo - mamy 11 bitów 011 1111 111
ror eax,12
mov ecx,dword PTR wynik + 4
add ecx,eax
mov dword PTR wynik + 4, ecx

;-------------------------
mov edi,OFFSET wynik ; Koniec g³ównej czêœci zadania
mov eax,edi

pop edi
pop esi
pop ecx
pop ebp
ret
_funkcja ENDP
END