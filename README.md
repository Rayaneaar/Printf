*This project has been created as part of the 42 curriculum by raaribou.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf()`. The goal of the project is to learn how **variadic functions** work in C (`<stdarg.h>`), how to parse a format string, and how to organise a small program into clean, extensible pieces. The result is a static library, `libftprintf.a`, created at the root of the repository with `ar`.

The prototype is:

```c
int ft_printf(const char *s, ...);
```

It writes the formatted output to the standard output and returns the number of characters printed, like the original `printf()`. As required by the subject, the buffer management of the original `printf()` is not implemented: output is written directly with `write`.

### Supported conversions

| Specifier | Description                                      |
|-----------|--------------------------------------------------|
| `%c`      | Prints a single character                        |
| `%s`      | Prints a string                                  |
| `%p`      | Prints a `void *` pointer in hexadecimal         |
| `%d`      | Prints a signed decimal (base 10) number         |
| `%i`      | Prints a signed integer in base 10               |
| `%u`      | Prints an unsigned decimal (base 10) number      |
| `%x`      | Prints a number in lowercase hexadecimal         |
| `%X`      | Prints a number in uppercase hexadecimal         |
| `%%`      | Prints a percent sign                            |

### Project structure

```
.
├── ft_printf.c           # Main function: walks through the format string
├── include/
│   └── ft_printf.h       # Prototypes and includes
├── src/
│   ├── handle_format.c   # Dispatches a specifier to the right function
│   ├── print_char.c      # %c (and %%)
│   ├── print_str.c       # %s
│   ├── print_nbr.c       # %d, %i
│   ├── print_unsigned.c  # %u
│   ├── print_hexa.c      # %x, %X
│   └── print_ptr.c       # %p
├── Makefile
└── README.md
```

## Instructions

### Compilation

From the root of the repository, run:

```bash
make
```

This compiles the sources with `cc -Wall -Wextra -Werror` and creates the library `libftprintf.a` at the root of the repository using `ar`.

Other Makefile rules:

```bash
make clean    # remove the object files
make fclean   # remove the object files and libftprintf.a
make re       # fclean, then all
```

### Usage

Include the header in your code and link against the library:

```c
#include "ft_printf.h"

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s, the answer is %d (0x%x)\n", "42", 42, 42);
	ft_printf("Characters printed: %d\n", count);
	return (0);
}
```

Compile and run:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -I include -o test
./test
```

## Explanation and justification of the algorithm and data structure

### Algorithm

`ft_printf` reads the format string once, from left to right:

1. Start the `va_list` with `va_start`.
2. Regular characters are written directly with `write`.
3. When a `%` is found, `handle_format` reads the specifier and calls the matching `print_*` function with the next argument (`va_arg`).
4. Each `print_*` function returns the number of characters it printed, and `ft_printf` adds it to a counter.
5. At the end, call `va_end` and return the counter.

Why this design?

- **Single pass:** each character is read exactly once, which is simple and fast.
- **One function per conversion:** every function stays short (Norm-friendly) and does one job. Adding a new specifier only means adding one function and one case in `handle_format`.
- **Returned counts:** the total length is built up naturally, without a global variable.
- **No `malloc`, no buffer:** numbers are printed digit by digit, so there is nothing to free and no memory leak is possible.

### Data structure

No custom data structure is needed. The program only uses the `va_list` to access the arguments one by one, and an `int` counter for the number of printed characters. Anything heavier would add complexity for no benefit, since one pass over the format string is enough.

## Resources

### References

- `man 3 printf`: behaviour of the original function
- `man 3 stdarg`: variadic functions (`va_start`, `va_arg`, `va_copy`, `va_end`)
- [GNU C Library: Formatted Output](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html)
- [cppreference: variadic arguments](https://en.cppreference.com/w/c/variadic)

### Use of AI

AI  was used for the following tasks only:

	- Printf edge cases and why it fails 
	- Giving resources of how the va_list work



