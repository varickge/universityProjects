; y = (abc - d/e)e
%include "io.inc"
section .data
    a dd 0 
    b dd 0
    c dd 0
    d dd 0
    e dd 0
    y dd 0
    R dd 0
    Q dd 0

section .text
global main

main: 
    mov ebp, esp
    xor eax, eax

    xor ebx, ebx        
    
    mov ebx, [a]
    
    imul ebx, [b]

    imul ebx, [c]

    mov eax, [d]

    mov ecx, [e]

    idiv ecx

    mov [Q], eax

    mov [R], edx

    sub ebx, [Q]

    imul ebx, [e]

    mov [y], ebx

    PRINT_DEC 4, [y]
    PRINT_DEC 4, [Q]
    PRINT_DEC 4, [R]

    ret