/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:40:03 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:04:23 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	x = 0;
	y = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[x] != '\0')
		x++;
	while (s2[y] != '\0')
		y++;
	if (x != y && x < n && y < n)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i != n)
	{
		if ((s1[i] - s2[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}
