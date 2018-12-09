
#include "../include/nm.h"

void	print_space(int nb)
{
	while (nb)
	{
		ft_putchar(' ');
		nb--;
	}
}

void	print_val(unsigned long val, unsigned char type, int bit)
{

	if (val == 0 && type != 'T')
		print_space(bit);
	else
	{
		ft_itoa_base(val, 16, bit);
	}
	ft_putchar(' ');
}

void	print_nm(t_print *print, char *name, int bit)
{
	if (name != NULL)
	{
		ft_putchar('\n');
		ft_putstr(name);
		ft_putstr(":\n");
	}
	while (print)
	{	
		if (ft_strncmp("radr", print->str, 4) != 0)
		{
			print_val(print->val, print->type, bit);
			ft_putchar(print->type);
			ft_putchar(' ');
			ft_putstr(print->str);
			ft_putchar('\n');
		}
		print = print->next;
	}
}
