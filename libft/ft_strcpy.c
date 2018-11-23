/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/13 00:03:29 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:02:59 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	n;
	char	c;

	n = 0;
	while (src[n] != '\0')
	{
		c = src[n];
		dest[n] = c;
		n++;
	}
	dest[n] = '\0';
	return (dest);
}
