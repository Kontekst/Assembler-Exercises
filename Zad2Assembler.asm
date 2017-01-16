.686
.model flat

extern _malloc :PROC

public _kopia_tablicy

.data
cztery db 4

.code

_kopia_tablicy PROC
push ebx
push ebp
push esi
mov ebp, esp

;/////////////////////////
; Rezerwacja pami�ci funkcj� malloc

mov eax, [ebp + 16]; EAX = Ilo�� element�w
mul cztery; EAX = Ilo�� element�w * 4 (Int ma 4 bajty)
push eax; Wprowadzenie argumentu dla funkcji malloc na stos
call _malloc; EAX = adres zarezerwowanego obszaru
;/////////////////////////
;Procedura zako�czenia funkcji w przypadku gdy malloc nie zaalokowa� pami�ci
     cmp eax,0 
     je koniec
;/////////////////////////

;/////////////////////////
mov edx, [ebp + 16]; EDX = Adres tablicy
mov ecx, [ebp + 20]; ECX = Ilo�� element�w
mov ebx, -4

przeniesienie:
add ebx, 4
mov esi, [edx + ebx]; EBX = Kolejny element tablicy

bt esi, 0; Sprwadzenie czy liczba jest parzysta, bit w pisany do flagi CF
jc wpisz_zero; Jump if Carry ( skacz gdy CF =1)

mov [eax + ebx],ebx
jmp dalej

wpisz_zero :
mov[eax + ebx], dword PTR 0
dalej:
dec ecx
cmp ecx,0
jne przeniesienie

koniec:
add esp,4
pop esi
pop ebp
pop ebx
ret
_kopia_tablicy ENDP

END
