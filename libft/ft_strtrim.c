/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:16:27 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:05:01 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	i = ft_strlen(str) - 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
		i--;
	str[i + 1] = '\0';
	return (ft_strdup(str));
}
