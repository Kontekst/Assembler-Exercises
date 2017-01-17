.686
.model flat

public _szyfruj

.code

_szyfruj PROC
push ebp
mov ebp,esp
push ebx
push esi
push edi

mov esi,[ebp + 8] ; EDX = adres na tablicê char

mov ebx, 52525252H
xor edi,edi ; EDX = licznik

petla:
mov dl,[esi + edi ]
xor bl,dl ; Zaszyfrowanie danych
mov [esi + edi ],  bl

xor eax,eax ; EAX bêdzie mia³ bit 30
bt ebx,30
rcl eax,1

xor ecx,ecx; ECX bêdzie mia³ bit 31 
bt ebx,31
rcl ecx,1

xor ecx,eax ; ECX = modulo 2 (bity 30,31)

shl ebx,1
add ebx, ecx
inc edi
cmp [esi + edi],byte PTR 0
jne petla


pop edi
pop esi
pop ebx
pop ebp
ret
_szyfruj ENDP
END