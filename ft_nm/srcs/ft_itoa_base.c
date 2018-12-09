
#include "../include/nm.h"
void	print_zero(int i)
{
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
}
void    ft_base(size_t n, int base, int i, int bit)
{
	char str[i];

    str[i] = '\0';
	if (base <= 10)
	{
		while (--i >= 0)
		{
			str[i] = (n % base) + 48;
			n = n / base;
		}
	}
	if (base > 10)
	{
		while (--i >= 0)
		{
			if (n % base > 9)
				str[i] = 'a' - 10 + (n % base);
			else
				str[i] = (n % base) + 48;
			n = n / base;
		}
	}
	print_zero(bit - ft_strlen(str));
	ft_putstr(str);
}

void    ft_itoa_base(unsigned long n, int base, int bit)
{
	unsigned long		x;
	int			i;

	i = 1;
	x = n;
	while (x >= (size_t)base)
	{
		x = x / base;
		i++;
	}
	(ft_base(n, base, i, bit));
}
