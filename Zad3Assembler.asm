.686
.model flat

extern _malloc :PROC

public _komunikat
.code
_komunikat PROC
push ebx
push ebp
push esi

mov ebp,esp
xor esi,esi
mov esi,[ebp + 16] ; EDX = Adres tablicy
mov eax,-1  ; EAX = liczba bajtów aktualnego tekstu

mov ebx,0
zliczanieIlosciBajtow:
inc eax ; Zwiêkszenie liczby bajtów aktualnego tekstu o 1
cmp [esi + eax], ebx ; Bajt = 0 w tablicy char oznacza koniec tekstu
jne zliczanieIlosciBajtow
add eax,1

mov ebx,eax
add eax,5 ; Tekst "B³¹d." Bêdzie na 5 bitach,wiêc trzeba je dodaæ do iloœci bitów tekstu pocz¹tkowego
call _malloc ; EAX = Adres zarezerwowanego obszaru

sub ebx,1 ; Aby nie przepisaæ '0' znajduj¹cego siê na koñcu tekstu
xor ecx,ecx ; ECX = 0

przepisywanie:
mov dl,byte PTR[esi + ecx]
mov [ eax + ecx ],dl ;Przepisanie bajtu po bajcie
inc ecx
cmp ecx,ebx
jne przepisywanie

mov [eax + ecx], byte PTR 'B' 
inc ecx
mov [eax + ecx], byte PTR 88H ; Latin 2 
inc ecx
mov [eax + ecx], byte PTR 0A5H
inc ecx
mov [eax + ecx], byte PTR 'd'
inc ecx
mov [eax + ecx], byte PTR '.'
inc ecx
mov [eax + ecx], byte PTR 0 

pop esi
pop ebp
pop ebx
ret
_komunikat ENDP
END