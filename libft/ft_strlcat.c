/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:07:47 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:03:38 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t d_len;
	size_t s_len;
	size_t res_len;

	d_len = ft_strlen((const char*)dest);
	s_len = ft_strlen(src);
	res_len = 0;
	if (d_len >= size)
		return (size + s_len);
	while (src[res_len] && (d_len + res_len < size - 1))
	{
		dest[d_len + res_len] = (char)src[res_len];
		res_len++;
	}
	dest[d_len + res_len] = '\0';
	return (d_len + s_len);
}
