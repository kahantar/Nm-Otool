/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:35:28 by kahantar          #+#    #+#             */
/*   Updated: 2018/12/25 12:53:38 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/otool.h"

void		ft_print_zero(int i)
{
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
}

void		ft_base(size_t n, int i, int bit)
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

void		ft_itoa_base(size_t n, int bit, int add)
{
	size_t		x;
	int			i;

	i = 1;
	x = n;
	while (x >= 16)
	{
		x = x / 16;
		i++;
	}
	if (i == 1 && add == 1)
		ft_putchar('0');
	(ft_base(n, i, bit));
}
