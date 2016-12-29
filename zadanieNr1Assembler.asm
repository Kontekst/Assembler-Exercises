.686
.model flat

public _roznica

.code

_roznica PROC
push ebp
mov ebp,esp

mov ecx, dword PTR [ebp + 8] ; Za�adowanie do ECX adresu zmiennej 'a'
mov edx, [ecx] ; Za�adowanie do EDX warto�ci zmiennej 'a'

push edx
fild dword PTR [esp] ; Za�adowanie pierwszej liczby ST(0)=a 
add esp,4

mov ecx, dword PTR [ebp + 12] ; Za�adowanie do ECX adresu na wska�nik(wsk)
mov edx, dword PTR [ecx]  ; Za�adowanie do EDX adresu zmiennej 'b' , na kt�r� wskazywa� wska�nik(wsk)
mov ecx, dword PTR [edx] ; Za�adowanie do ECX warto�ci zmiennej 'b'

push ecx
fild dword PTR [esp] ; Za�adowanie drugiej liczby ST(0)= b ST(1)= a
add esp,4

fsubp st(1),st(0) ; ST(0)= (a - b)
fistp dword PTR [ebp + 8] ; Zapisanie r�nicy w kodzie U2 na stosie
mov eax, dword PTR [ebp + 8] ; Warto�� zwracamy rejestrem eax


pop ebp
ret
_roznica ENDP

END