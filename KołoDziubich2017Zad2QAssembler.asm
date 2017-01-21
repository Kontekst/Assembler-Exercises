.686
.model flat
 
public _ciag
.data
trojka dd 3.0
minusjeden dd -1
.code
 
_ciag PROC
push ebp
mov ebp,esp
 
mov edx,[ebp + 8]
 
cmp edx,1
je jedynka
 
cmp edx,2
je dwojka
jmp inne
 
jedynka:
mov eax, 5 ; x=1
jmp konwersja
 
dwojka:
mov eax, 6 ; x=2
jmp konwersja
 
inne:
mov ecx,edx ; EDX = x ;
push edx
dec ecx ;  ECX = (x-1)
push ecx
call _ciag ; Ciag(x -1)  EAX = wynik ( w double)
; ST(0) = eax czyli wyni kw postaci double
add esp,4
fild dword PTR minusjeden ;ST(0)= -1.0 st(1) = ciag
fmulp st(1),st(0) ; ST(0) = -(ciag)
fld dword PTR trojka ; ST(0)=3.0 ST(1) = -(ciag)
faddp st(1),st(0) ; st(0)= 3 -(ciag)
 
pop edx
push edx
fild dword PTR [esp]
add esp,4  ; ST(0) = x ST(1) = 3 -(ciag)
fdivp st(1),st(0)
jmp koniec
 
konwersja:
 
push eax
fild dword PTR [esp]
add esp,4
 
koniec:
pop ebp
ret
_ciag ENDP
END
