.686
.model flat

public _kwadrat
.code

_kwadrat PROC
push ebp
mov ebp,esp
push ebx
mov ebx,[ebp + 8] ; EDX = argument funkcji

cmp ebx,0
je zwracamyZero
cmp ebx,1
je zwracamyJeden

sub ebx,2
push ebx
call _kwadrat ; Wywo³ujemy funkcje rekurenccyjnie kwadrat(a - 2)
add esp,4
add ebx,2 ; EDX = a, EAX = kwadrat (a - 2)

xchg ebx,eax ; EAX = a, EDX = kwadrat (a - 2)
mov ecx,4
mul ecx ; EAX = 4*a, EDX = kwadrat (a - 2)
add eax,ebx ;  EAX = kwadrat (a - 2) + 4*a
sub eax,4 ; EAX = kwadrat (a - 2) + 4*a - 4
jmp koniec 

zwracamyZero:
mov eax,0 ; Wynik zwracany dla przypadku gdy a = 0
jmp koniec

zwracamyJeden:
mov eax,1 ; Wynik zwracany dla przypadku gdy a = 1

koniec:
pop ebx
pop ebp
ret
_kwadrat ENDP
END