/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:18:34 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:01:25 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*str;
	const	char	*s;
	size_t			i;

	i = 0;
	str = (char*)dest;
	s = (char*)src;
	while (i < n)
	{
		str[i] = s[i];
		if (s[i] == c)
			return (&str[i + 1]);
		i++;
	}
	return (NULL);
}
