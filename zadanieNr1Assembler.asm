.686
.model flat

public _roznica

.code

_roznica PROC
push ebp
mov ebp,esp


;Wersja krótka
mov eax, [ebp + 8] ; EAX = &a // adres odjemnej
mov eax, [eax]; EAX = a // odjemna


mov edx, [ebp + 12] ; EDX = &wsk // adres adresu odjemnika
mov edx, [edx]  ; EDX = &b // adres odjemnika
mov edx, [edx] ; EDX = b // odjemnik

sub eax,edx ; EAX = a - b // zwraca ( a - b )

;/////////////////////////////////

;Korzystając z koprocesora arytmetycznego
;mov ecx, dword PTR [ebp + 8] ; Załadowanie do ECX adresu zmiennej 'a'
;mov edx, [ecx] ; Załadowanie do EDX wartości zmiennej 'a'

;push edx
;fild dword PTR [esp] ; Załadowanie pierwszej liczby ST(0)=a 
;add esp,4

;mov ecx, dword PTR [ebp + 12] ; Załadowanie do ECX adresu na wskaźnik(wsk)
;mov edx, dword PTR [ecx]  ; Załadowanie do EDX adresu zmiennej 'b' , na którą wskazywał wskażnik(wsk)
;mov ecx, dword PTR [edx] ; Załadowanie do ECX wartości zmiennej 'b'

;push ecx
;fild dword PTR [esp] ; Załadowanie drugiej liczby ST(0)= b ST(1)= a
;add esp,4

;fsubp st(1),st(0) ; ST(0)= (a - b)
;fistp dword PTR [ebp + 8] ; Zapisanie różnicy w kodzie U2 na stosie
;mov eax, dword PTR [ebp + 8] ; Wartość zwracamy rejestrem eax
;/////////////////////////////////

pop ebp
ret
_roznica ENDP

END
