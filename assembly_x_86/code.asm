%include "io.inc"
section .data
    array dd 12, 23, 2, 52, 9
    length dd 5
    max dd 0
    count dd 0

section .text
global main

main:
    mov ebp, esp
    xor eax, eax

    xor ebx, ebx        
    
    mov ecx, [length]
    
    xor esi, esi
    
    lea ebx, [array]
    
    mov eax,[ebx, esi*4]
    
    loop: inc esi
    
    dec ecx
    
    jz stop
    
    cmp eax,[ebx, esi*4] 
    
    jg loop
    mov eax,[ebx, esi*4]
    jmp loop 
    
    stop:
    PRINT_STRING "Max value is: " 
    PRINT_DEC 4, eax 
    mov [max], eax
    
    neg eax
    NEWLINE
    PRINT_STRING "Negative value of maximum: " 
    PRINT_DEC 4, eax 
    
    xor ebx, ebx
    ;mov eax, -1 ;for testing code
    bsr ecx, eax
    add ecx, 2
    loop1:
    dec ecx
    jz stop1
    rcr eax, 1
    jc plus
    jmp loop1
    
    plus:
    add ebx, 1
    jmp loop1
    
    stop1:
    mov [count], ebx
    NEWLINE
    PRINT_STRING "Count of 1 is: " 
    PRINT_DEC 4, count
    
    ret