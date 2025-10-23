    .section .data
msg:
    .asciz "Hello from ARM Assembly on WSL!\n"

    .section .text
    .global _start

_start:
    ldr r0, =msg        @ Load address of string into r0
    bl print_string     @ Call function to print message

    mov r7, #1          @ syscall: sys_exit
    mov r0, #0          @ exit code 0
    svc 0               @ make system call

@ -----------------------------------------------------
@ print_string: writes string to stdout (fd = 1)
@ Arguments:
@   r0 = pointer to string
@ -----------------------------------------------------
print_string:
    mov r1, r0          @ r1 = string pointer

@ Compute string length dynamically
get_len:
    ldrb r3, [r1], #1   @ Load next byte and increment pointer
    cmp r3, #0          @ Check for null terminator
    bne get_len
    sub r2, r1, r0      @ r2 = length including null terminator
    sub r2, r2, #1      @ subtract 1 to exclude '\0'

    mov r1, r0          @ reset r1 = string pointer
    mov r0, #1          @ stdout (fd = 1)
    mov r7, #4          @ syscall: sys_write
    svc 0
    bx lr               @ return
