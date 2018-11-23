/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strqu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:53:56 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:03:16 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[x] != '\0')
		x++;
	while (s2[y] != '\0')
		y++;
	if (x != y)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((s1[i] - s2[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}
