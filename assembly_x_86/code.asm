%include "io.inc"
section .data
    array dd 12, 23, 2, 52, 9
    lenght dd 5
    max dd 0

section .text
global main

main:
    mov ebp, esp
    xor eax, eax

    xor ebx, ebx        
    
    mov ecx, [lenght]
    
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
    PRINT_STRING ", Negative value of maximum: " 
    PRINT_DEC 4, eax 
    
    ret