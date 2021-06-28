Week 1 Program Source Files
- - - - - - - - - - - - - - 

This folder contains the hello world program in the file hello.c.   I have also included a corresponding C/Assembly code file that will show both the C code and corresponding assembly code.   

hello.c - The C source program
hello.s - The C/Assembly Code (just a simple text file)

If using gcc, you get get these files as well as an executable (a.out) by running:

    gcc -Wa,-adhln -g hello.c > hello.s

If you don’t care about seeing the assembly language, you can just load the hello.c file  into your compiler, or compile the file using gcc as:

    gcc hello.c

Note that you can use any compiler and coding environment in this class, but the important thing to understand here is the overall compilation process deployed by a C or C++ compiler.