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
shr eax,3 ; Usuni�cie 3 bit�w kt�re b�d� na m�odszych bitach wyniku
mov dword PTR [wynik + 4], eax ; Przepisanie 20 bit�w na starsze 32 bity zmiennej 'wynik'

mov eax,esi
and eax, 00000007H
ror eax,3 ; 3 pozosta�e bity mantysy, kt�re przepisujemy do m�odszej cz�ci bit�w zmiennej wynik, musz� by� po skrajnie lewej stronie 
mov dword PTR [wynik] , eax ; Przepisanie 3 bit�w na starsze 32 bity zmiennej 'wynik'
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
and eax,7F800000H ; Wyodr�bnienie bit�w wyk�adnika
rol eax,9
sub eax,7FH ; Wyk�adnik w formacie 'float' jest przesuni�ty o 7FH // Przesuni�cie bitowo - mamy 8 bit�w 0111 111( czyli 7FH ) i dodaje si�  do niego  wyk�adnik aby uzyska� liczb� w formacie 'float'
add eax,3FFH; Wyk�adnik w formacie 'double' musimy przsun�� o 3FFH // Przesuni�cie bitowo - mamy 11 bit�w 011 1111 111
ror eax,12
mov ecx,dword PTR wynik + 4
add ecx,eax
mov dword PTR wynik + 4, ecx

;-------------------------
mov edi,OFFSET wynik ; Koniec g��wnej cz�ci zadania
mov eax,edi

pop edi
pop esi
pop ecx
pop ebp
ret
_funkcja ENDP
END