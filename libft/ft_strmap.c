/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:04:51 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:03:53 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (s[n] != '\0')
	{
		str[n] = f(s[n]);
		n++;
	}
	str[n] = '\0';
	return (str);
}
