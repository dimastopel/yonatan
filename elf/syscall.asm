; syscall.asm


struc Point
alignb 4
.x: resb 1 
.y: resb 1
endstruc


struc sysinfo 
;alignb 4
   uptime: resb 8                  ;/* Seconds since boot */
   loads: resb 24                  ;/* 1, 5, and 15 minute load averages */
   totalram: resb 8                ;/* Total usable main memory size */
   freeram: resb 8                 ;/* Available memory size */
   sharedram: resb 8               ;/* Amount of shared memory */
   bufferram: resb 8               ;/* Memory used by buffers */
   totalswap: resb 8               ;/* Total swap space size */
   freeswap: resb 8                ;/* Swap space still available */
   procs: resb 2                   ;/* Number of current processes */
   totalhigh: resb 8               ;/* Total high memory size */
   freehigh: resb 8                ;/* Available high memory size */
   mem_unit: resb 4                ;/* Memory unit size in bytes */
endstruc

section .data
    hello_world db "Hello world!", 10
    hello_world_len  equ $ - hello_world

    char_to_print db "0"


    point: istruc Point
    at Point.x, db 1
    at Point.y, db 2
    iend

    const10:    dd 10

section .bss
    point2: resb Point_size
    sys: resb sysinfo_size 

section .text

    global _start
    _start:
        call _modify
        mov rax, qword [sys + 0]
        call _printNumber
        mov rax, 10
        call _printCharacter
        call _getsysinfo
        mov rax, qword [sys + 0]
        ;mov rax, 15
        call _printNumber
        mov rax, 10
        call _printCharacter
        call _print
        mov rax, 60
        mov rdi, 0
        syscall


    _print:
        mov rax, 1
        mov rdi, 1
        mov rsi, hello_world
        mov rdx, hello_world_len
        syscall
        ret

    _modify:
        mov byte [hello_world], 'A'
        mov word [hello_world+1], 'B'
        ret



    _getsysinfo:
        mov rax, 99
        mov rdi, sys
        syscall
        ret


;Input
; eax = number to display


    _printNumber:
        push rax
        push rdx
        xor rdx,rdx          ;edx:eax = number
        div dword [const10]  ;eax = quotient, edx = remainder
        test rax,rax         ;Is quotient zero?
        je .l1               ; yes, don't display it
        call _printNumber     ;Display the quotient
    .l1:
        lea rax,[rdx+'0']
        call _printCharacter  ;Display the remainder
        pop rdx
        pop rax
        ret

    _printCharacter:
        mov byte [char_to_print], al
        mov rax, 1
        mov rdi, 1
        mov rsi, char_to_print
        mov rdx, 1
        syscall
        ret




