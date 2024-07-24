#include "ft_printf.h"

int	ft_putnbrbase(unsigned long nbr, char *base)
{
	int  len;
	unsigned long size;

	size = ft_strlen(base);
    len = 0;
	if (nbr == 0)
			return (len += ft_putstr("(nil)"));
    if (nbr >= size - 1)
	{
        len += ft_putnbrbase(nbr / size, base);
    	len += ft_putnbrbase(nbr % size, base);
	}
	return(len);
}

int	ft_print_pointer(unsigned long ptr)
{
	int len = 0;

	// Affichage du préfixe "0x"
	len += write(1, "0x", 2);
	
	// Affichage de l'adresse en base hexadécimale
	len += ft_putnbrbase(ptr, "0123456789abcdef");

	return (len);
}

