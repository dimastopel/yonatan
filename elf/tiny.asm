 ; tiny.asm
  section .text
  global _start
  _start:
                mov     rax, 60
                mov     rdi, 42  
                ;xor     rdi, rdi  
                syscall



