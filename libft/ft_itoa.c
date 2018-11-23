/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:56:28 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:00:34 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	x;
	long int	z;

	i = 1;
	z = n;
	if (z < 0)
		z = z * -1;
	x = z;
	while (x > 9)
	{
		x = x / 10;
		i++;
	}
	if (!(str = ft_strnew(sizeof(char) * (i + (n < 0 ? 2 : 1)))))
		return (NULL);
	while (--i >= 0)
	{
		str[i] = z % 10 + 48;
		z = z / 10;
	}
	if (n < 0)
		str = ft_strjoin("-", str);
	return (str);
}
