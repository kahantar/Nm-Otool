/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:07:57 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:04:33 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(char *str, const char *to_find, size_t len)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (str[i] == to_find[j] && (size_t)i < len)
		{
			i++;
			j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i - j]);
		}
		i = i - j;
		i++;
	}
	return (NULL);
}
