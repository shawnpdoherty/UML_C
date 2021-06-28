   1                    .file   "hello.c"
   2                    .text
   3                .Ltext0:
   4                    .section    .rodata
   5                .LC0:
   6 0000 48656C6C      .string "Hello World"
   6      6F20576F
   6      726C6400
   7                    .text
   8                    .globl  main
  10                main:
  11                .LFB0:
  12                    .file 1 "hello.c"
   1:hello.c       **** #include <stdio.h>
   2:hello.c       ****
   3:hello.c       **** int main(void) {
  13                    .loc 1 3 0
  14                    .cfi_startproc
  15 0000 55            pushq   %rbp
  16                    .cfi_def_cfa_offset 16
  17                    .cfi_offset 6, -16
  18 0001 4889E5        movq    %rsp, %rbp
  19                    .cfi_def_cfa_register 6
   4:hello.c       ****   printf("Hello World\n");
  20                    .loc 1 4 0
  21 0004 488D3D00      leaq    .LC0(%rip), %rdi
  21      000000
  22 000b E8000000      call    puts@PLT
  22      00
   5:hello.c       ****   return 0;
  23                    .loc 1 5 0
  24 0010 B8000000      movl    $0, %eax
  24      00
   6:hello.c       **** }
  25                    .loc 1 6 0
  26 0015 5D            popq    %rbp
  27                    .cfi_def_cfa 7, 8
  28 0016 C3            ret
  29                    .cfi_endproc
  30                .LFE0:
  32                .Letext0:
  33                    .file 2 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h"
  34                    .file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
  35                    .file 4 "/usr/include/x86_64-linux-gnu/bits/libio.h"
  36                    .file 5 "/usr/include/stdio.h"
  37                    .file 6 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"