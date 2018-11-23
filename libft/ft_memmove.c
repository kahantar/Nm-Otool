/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:00:37 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:01:47 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;

	destination = (char*)dest;
	source = (char*)src;
	if (source < destination && n > 0)
	{
		while ((int)--n >= 0)
			destination[n] = source[n];
		return (destination);
	}
	else
		return (ft_memcpy(dest, src, n));
}
