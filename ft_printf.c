#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_print_pointer(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putnbr_un(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_putnbrbase(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		len += ft_putnbrbase(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(arguments, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			len += ft_format(arguments, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
	}
	va_end(arguments);
	return (len);
}
