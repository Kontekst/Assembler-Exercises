.686
.model flat
 
public _funkcja
 
.code
 
_funkcja PROC
push ebp
mov ebp,esp
mov ebx, [ebp + 8]
 
rol ebx,9
sub ebx,4
ror ebx,9
 
push ebx
finit
fld dword PTR [esp]
add esp,4
 
pop ebp
ret
_funkcja ENDP
 
END
