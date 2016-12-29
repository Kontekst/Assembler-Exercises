.686
.model flat

public _roznica

.code

_roznica PROC
push ebp
mov ebp,esp

mov ecx, dword PTR [ebp + 8] ; Za³adowanie do ECX adresu zmiennej 'a'
mov edx, [ecx] ; Za³adowanie do EDX wartoœci zmiennej 'a'

push edx
fild dword PTR [esp] ; Za³adowanie pierwszej liczby ST(0)=a 
add esp,4

mov ecx, dword PTR [ebp + 12] ; Za³adowanie do ECX adresu na wskaŸnik(wsk)
mov edx, dword PTR [ecx]  ; Za³adowanie do EDX adresu zmiennej 'b' , na któr¹ wskazywa³ wska¿nik(wsk)
mov ecx, dword PTR [edx] ; Za³adowanie do ECX wartoœci zmiennej 'b'

push ecx
fild dword PTR [esp] ; Za³adowanie drugiej liczby ST(0)= b ST(1)= a
add esp,4

fsubp st(1),st(0) ; ST(0)= (a - b)
fistp dword PTR [ebp + 8] ; Zapisanie ró¿nicy w kodzie U2 na stosie
mov eax, dword PTR [ebp + 8] ; Wartoœæ zwracamy rejestrem eax


pop ebp
ret
_roznica ENDP

END