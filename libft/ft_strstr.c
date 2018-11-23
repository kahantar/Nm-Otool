/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 15:09:58 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:04:51 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(char *str, const char *to_find)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		while (str[i + n] == to_find[n])
		{
			n++;
			if (to_find[n] == '\0')
				return (&str[i]);
		}
		n = 0;
		i++;
	}
	return (to_find[0] == 0 ? str : NULL);
}
