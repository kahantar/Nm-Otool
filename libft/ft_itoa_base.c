/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:53:05 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:00:38 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_base(long int n, int base, int i)
{
	char *str;

	str = ft_strnew(i + 1);
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
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_base(long int n, int base)
{
	long int	x;
	int			i;

	i = 1;
	x = n;
	while (x >= base)
	{
		x = x / base;
		i++;
	}
	return (ft_base(n, base, i));
}
