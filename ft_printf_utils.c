#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	size_t	i;
	int		len;

	len = 0;
	i = 0;
	if (!s)
		return(0);
	while (s[i])
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		len += ft_putstr("-2147483648");
	else if (n == 2147483647)
		len += ft_putstr("2147483647");
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	len +=ft_putchar((n % 10) + '0');
	return (len);
}

int	ft_putnbr_un(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_un(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}
