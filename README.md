C-with-Inline-Assembly-GCC
==========================

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
                          
