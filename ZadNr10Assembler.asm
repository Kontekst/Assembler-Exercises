.686
.model flat
 
public _funkcja
.data
.code
 
_funkcja PROC
push ebp
mov ebp,esp
push esi
push edi
mov esi,[ebp + 8] ; ESI = x 
mov edi,[ebp + 12] ; EDI = y
;  liczba w ESI >  liczba EDI wtedy  STC w przeciwnym razie CLC

bt edi,31 ; bit o wadze 2^24
jc ediWieksze 

shl edi,1 ; Jeœli bit o wadze 2^24 = 0 to mo¿emy EDI przesun¹æ o 1 i obie liczby s¹ w tym samym formacie

cmp esi,edi
jbe ediWieksze; Jump if below or equal. Skoki dla liczb typu unsigned !
stc ; Tu koñczy siê treœæ g³ówna zadania ESI > EDI
mov eax,0
jmp koniec

ediWieksze: ; EDI >ESI
clc ; Tu koñczy siê treœæ g³ówna zadania EDI >= ESI
mov eax,1
 
 koniec:
pop edi
pop esi
pop ebp
ret
_funkcja ENDP
END