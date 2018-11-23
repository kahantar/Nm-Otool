/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:03:24 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:03:33 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		n;
	int		c;

	c = 0;
	n = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[n] != '\0')
	{
		str[n] = s1[n];
		n++;
	}
	while (s2[c] != '\0')
	{
		str[n] = s2[c];
		n++;
		c++;
	}
	str[n] = '\0';
	return (str);
}
