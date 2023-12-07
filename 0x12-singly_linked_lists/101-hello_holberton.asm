section .data
    hello_message db "Hello, Holberton", 0

section .text
    global main

extern printf

main:
    mov rdi, hello_message
    call printf

    ; Exit the program
    xor eax, eax
    ret

