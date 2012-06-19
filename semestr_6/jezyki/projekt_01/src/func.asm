db input
db 1: func1; 2: func2; 3: quit
db wewnatrz funkcji 1
db wewnatrz funkcji 2
db Bledna opcja
call 35
mov ax 1
mov bx 0
int 2
cmp cx 1
jz 19
cmp cx 2
jz 24
cmp cx 3
jnz 30
mov ax 13 
int 8


mov ax 1
mov bx 2
int 1
jmp 5

mov ax 1
mov bx 3
int 1
jmp 5


mov ax 1
mov bx 4
int 1
jmp 5

mov ax 1
mov bx 1
int 1
mov ax 2
mov bx 0
int 1
ret
