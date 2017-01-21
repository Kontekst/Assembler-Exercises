.686
.model flat
 
public _XYZ2R
extern _malloc :PROC
.data
wynik dd 0.0
.code
 
_XYZ2R PROC
push ebp
mov ebp,esp
push ebx
push esi
push edi
 
mov esi,[ebp +8] ; ESI = Adres tablicy
mov eax,[ebp + 12] ; EAX = n /3   n to liczba elemnt�w tablicy
mov edx,12 ; Aby wyliczy� liczb� bajt�w kt�re musi przyj�� _malloc
; musz� drugi parametr znajduj�cy si� teraz w eax pomno�y� przez 3
; wtedy mam liczb� danych typu float w tablicy,
; i jeszczepomno�y� razy 4, poniewa� float ma 4 bajty
mul edx ; EAX = liczba bajt�w dla funkcji malloc
 
push edx
call _malloc ; EAX = adres zarezerwowanej pami�ci,czyli naszej nowej tablicy, ju� do ko�ca programu go nie zmieniam
add esp,4
 
mov ecx,[ebp+12] ; ECX = n /3
 
 
push eax ; Zapisz� adres na p�niej, poniewa� w p�tli b�d� go zmienia�
 
poczatekPetli:
finit ; Mo�liwe �e nawet niepotrzebne w tym programie
push ecx ;ECX pomocniczo
 
mov ecx,dword PTR [esi]
 
push ecx
fld dword PTR [esp] ; ST(0)= X
add esp,4
 
add esi,4
add eax,4
mov ecx,dword PTR [esi]
 
push ecx
fld dword PTR [esp] ; ST(0) = Y, ST(1) = X
add esp,4
 
mov [eax],ecx ; Przepisanie drugiej liczby z tr�jki do nowej tablicy
add esi,4
add eax,4
mov ecx,dword PTR [esi]
 
push ecx
fld dword PTR [esp] ; ST(0) = Z, ST(1) = Y, ST(2) = X
add esp,4
 
mov [eax],ecx ; Przepisanie trzeciej liczby z tr�jki do nowej tablicy
sub esi,8
sub eax,8
 
 
;W�a�ciwa konwersja ;3.063*x - 1.393*y - 0.476*z
; ST(0) = Z, ST(1) = Y, ST(2) = X
;////////////////////////////////////////////////////////////////////
mov ecx,3063
push ecx
fild dword PTR [esp] ; ST(0)= 3063, ST(1) = Z, ST(2) = Y, ST(3) = X
mov ecx,1000
push ecx
fild dword PTR [esp] ; ST(0) = 1000, ST(1)= 3063, ST(2) = Z, ST(3) = Y, ST(4) = X
add esp,8
 
fdivp st(1),st(0) ; ST(0)= 3.063, ST(1) = Z, ST(2) = Y, ST(3) = X
fmulp st(3),st(0) ; ST(0) = Z, ST(1) = Y, ST(2) = X*3,063
;////////////////////////////////////////////////////////////////////
mov ecx,1393
push ecx
fild dword PTR [esp]
mov ecx,1000
push ecx
fild dword PTR [esp] ; ST(0) = 1000, ST(1)= 1393, ST(2) = Z, ST(3) = Y, ST(4) = X*3,063
add esp,8
 
fdivp st(1),st(0) ; ST(0)= 1.393, ST(1) = Z, ST(2) = Y, ST(3) =  X*3,063
fmulp st(2),st(0) ; ST(0) = Z, ST(1) = Y*1.393, ST(2) = X*3,063
;////////////////////////////////////////////////////////////////////
 
mov ecx,476
push ecx
fild dword PTR [esp]
mov ecx,1000
push ecx
fild dword PTR [esp] ; ST(0) = 1000, ST(1)= 476, ST(2) = Z, ST(3) = *1.393, ST(4) = X*3,063
add esp,8
 
fdivp st(1),st(0) ; ST(0)= 0.476, ST(1) = Z, ST(2) = *1.393, ST(3) =  X*3,063
fmulp st(1),st(0) ; ST(0) = Z*0.476, ST(1) = Y*1.393, ST(2) = X*3,063
;////////////////////////////////////////////////////////////////////
fsubp st(2),st(0) ; ST(0)= Y*1.393 ST(1) = ( X*3.063 - Z*0.476 )
fsubp st(1),st(0); ST(0) = ( X*3.063 - Z*0.476 - Y*1.393 )
;Wynik mamy na wierzcho�ku koprocesora
fstp dword PTR wynik
mov ecx,dword PTR wynik
mov [eax],ecx ; Zapisanie wyniku do pierwszgo floata z tr�jki
 
add eax,12 ;Przesuni�cie o kolejne 3 elementy
add esi,12
pop ecx ; Przywr�cenie ecx, aby m�c kontrolowa� p�tle
dec ecx
jne poczatekPetli
 
pop eax  ; Wczytuje adres
pop edi
pop esi
pop ebx
pop ebp
ret
_XYZ2R ENDP
END