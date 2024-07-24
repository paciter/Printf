#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_strlen(char *s);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr_un(unsigned int n);
int	ft_putnbr(int n);
int	ft_format(va_list args, const char format);
int	ft_putnbrbase(unsigned long nbr, char *base);
int	ft_printf(const char *format, ...);
int	ft_print_pointer(unsigned long ptr);

#endif