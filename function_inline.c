/*
          Author: Dung Harry
          Date created: 9th, December 2013
          Operating System: Ubuntu 13.10 Desktop x86_64
          Compiler: GNU compiler 4.8.1

          Description: this is an example about how to call the printf, scanf functions with AT&T inline assembly language in GNU C compiler GCC

          Copy the content of this doc and store in the file that has name function_inline.c

          Compile and run the program by using following commands:
                  - For gcc x86_64 version:
                          gcc -m32 -c function_inline.c
                          gcc -m32 -o function_inline function_inline.o
                          ./function_inline

                 - For gcc x86 version:
                          gcc -c function_inline.c
                          gcc -o function_inline function_inline.o
                          ./function_inline
*/

#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    int *piValue = (int *) malloc(sizeof(int));
    char *pcStr = "Enter a integer number: ";
    char *pcInputFormat = "%d";
    char *pcFormat = "The integer value that you was entered is: %d\n";

    asm (
        "movl %0, %%eax\n"
        "pushl %%eax\n"
        "call printf\n"
        "popl %%ebx\n"
        :
        : "r" (pcStr)
    );

    asm (
        "movl %0, %%ecx\n"
        "pushl %%ecx\n"
        "movl %1, %%eax\n"
        "pushl %%eax\n"
        "call scanf\n"
        "popl %%ebx\n"
        "popl %%ebx\n"
        :
        : "r" (piValue), "r" (pcInputFormat)
    );

    asm (
        "movl (%0), %%eax\n"
        "pushl %%eax\n"
        "movl %1, %%eax\n"
        "pushl %%eax\n"
        "call printf\n"
        "popl %%ebx\n"
        "popl %%ebx\n"
        :
        : "r" (piValue), "r" (pcFormat)
    );
}
