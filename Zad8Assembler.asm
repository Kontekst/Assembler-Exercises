.686
.model flat

public _funkcja

.code

_funkcja PROC
push ebp
mov ebp,esp
mov edx,[ ebp + 8 ]
shr edx,7 ; Zostawiam tylko bity kt�re maj� minimaln� wag� 2^0, 2^1, 2^2 itd.
cmp edx,0 ; Sprawdzam cz�� ca�kowit�
je zero
mov eax,1 ; Dla wypisania wyniku na konsoli, r�ne od zera
stc ; set carry flag = 1
jmp koniec

zero:
mov eax,0 ; Dla wypisania wyniku na konsoli, zero
clc ; clear carry flag = 0

koniec:

pop ebp
ret
_funkcja ENDP
END