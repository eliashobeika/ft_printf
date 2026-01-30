# Intro
This is one of the three projects for milestone 1 of 42Beirut's curriculum.
In it, I reimplemented the famous `printf` function we all know and love.

# Skills demonstrated
- C programming (pointers, memory management, variadic functions...)
- Understanding of standard C library functions
- Makefile usage
- Adherence to 42 Norm coding standards/practices.

# How to run
> **Note:** This project assumes a Linux environment. It won't work on Windows.
## Main functions
1. Clone this repo in your working directory.
2. Run `make all`
3. Add your .c source file that includes main (we'll call it main.c). Don't forget to include "libftprintf.a" in it to use `ft_printf`.
4. Run `cc main.c libftprintf.a -o my_program`
5. Run `./my_program`

# Cleanup
After compiling the library, you can run
1. `make clean` to delete all .o files created previously (This keeps libftprintf.a)
2. `make fclean` to delete all .o files created previously and libftprintf.a
3. `make re` as a shortcut for "make fclean" followed by "make all"

# Implementation
## Conversions implemented
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.
## Limitations
- Flags are not implemented.

# Examples
```c
ft_printf("Hello World!"); //output: Hello World!
ft_printf("Hello %s!", "stranger"); //output: Hello stranger!
```
