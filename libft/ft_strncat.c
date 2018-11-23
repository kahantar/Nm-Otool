/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 01:50:56 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:04:07 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	int		i;
	int		n;
	int		x;

	n = 0;
	i = 0;
	x = 0;
	(void)nb;
	while (dest[i] != '\0')
		i++;
	while (src[n] != '\0' && x < (int)nb)
	{
		dest[i] = src[n];
		i++;
		n++;
		x++;
	}
	dest[i] = '\0';
	return (dest);
}
