
#include "../include/otool.h"

void	ft_print_zero(int i)
{
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
}

void    ft_base(size_t n, int i, int bit)
{
	char str[i];

    	str[i] = '\0';
	while (--i >= 0)
	{
		if (n % 16 > 9)
			str[i] = 'a' - 10 + (n % 16);
		else
			str[i] = (n % 16) + 48;
		n = n / 16;
	}
	ft_print_zero(bit - ft_strlen(str));
	ft_putstr(str);
}

void    ft_itoa_base(size_t n, int bit)
{
	size_t			x;
	int			i;

	i = 1;
	x = n;
	while (x >= 16)
	{
		x = x / 16;
		i++;
	}
	if (i == 1)
		ft_putchar('0');
	(ft_base(n, i, bit));
}
