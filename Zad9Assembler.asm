.686
.model flat

public _funkcja

.code

_funkcja PROC
push ebp
mov ebp,esp
mov edx,[ ebp + 8 ]
bt edx,6 ; Je�li jest jedynka na tym bicie to mamy 1/2 i w ka�dym takim przypadku zaokr�glamy w g�r�
jc podwyzszamy
mov eax,0 ; 1 oznacza �e zaokr�glamy w g�r� // Tylko dla wy�wietlenia wyniku
shr edx,7
shl edx,7
jmp koniec
podwyzszamy:
mov eax,1 ; 0 oznacza �e zaokr�glamy w d� // Tylko dla wy�wietlenia wyniku
shr edx,7
inc edx
shl edx,7
koniec:
pop ebp
ret
_funkcja ENDP
END