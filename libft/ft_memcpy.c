/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 11:14:37 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:01:37 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*str;
	const	char	*s;

	i = 0;
	str = (char*)dest;
	s = (char*)src;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
