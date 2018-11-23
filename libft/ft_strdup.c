/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:10:49 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:03:11 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*m;
	int		i;
	int		x;

	x = 0;
	i = 0;
	while (src[x] != '\0')
		x++;
	x++;
	m = (char *)malloc(sizeof(char) * x);
	if (!m)
		return (NULL);
	while (src[i] != '\0')
	{
		m[i] = src[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}
