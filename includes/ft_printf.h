
#ifndef FT_PRINTF_H

#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct s_conv {
  char spec;
  int (*handler)(va_list *ap);
} t_conv;

int ft_printf(const char *str, ...);

size_t ft_stlen(char *s);

int get_printed_numbers(int nbr);

char *ft_itoa_base(int i, int base);
int print_char(char c);

int print_nbr(int n);

int print_hex_lower(int n);
int print_hex_upper(int n);
int print_ptr(void *ptr);
int print_str(char *s);
int print_unsigned(unsigned int n);
int print_hex_ptr(unsigned long long nbr);

int handle_format(char spec, va_list args);

size_t ft_strlen(char *c);
#endif
