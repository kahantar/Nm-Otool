/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 09:20:25 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:04:45 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_words(char const *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if ((str[i] != c) && (str[i] != '\0'))
			j++;
		while ((str[i] != c) && (str[i] != '\0'))
			i++;
	}
	return (j);
}

static int		*ft_how_many(char const *str, char c)
{
	int		i;
	int		j;
	int		k;
	int		*tabl;

	i = 0;
	j = 0;
	if (!(tabl = (int*)malloc(sizeof(*tabl) * (ft_words(str, c) + 1))))
		return (NULL);
	while ((str[i]) && (j < ft_words(str, c)))
	{
		k = 0;
		while (str[i] == c)
			i++;
		while ((str[i] != c) && (str[i] != '\0'))
		{
			i++;
			k++;
		}
		tabl[j] = k;
		j++;
		i++;
	}
	tabl[j] = 0;
	return (tabl);
}

static char		**ft_push(char **tab, int *tabl, char const *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (i < ft_words(str, c))
	{
		k = 0;
		while (str[j] == c)
			j++;
		while (k < tabl[i])
		{
			tab[i][k] = str[j];
			k++;
			j++;
		}
		tab[i][k] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		*tabl;
	int		i;

	if (str <= 0)
		return (NULL);
	i = 0;
	tab = (char**)malloc(sizeof(*tab) * (ft_words(str, c) + 1));
	if (!tab)
		return (NULL);
	tabl = ft_how_many(str, c);
	while (i <= ft_words(str, c))
	{
		tab[i] = (char*)malloc(sizeof(**tab) * (tabl[i] + 1));
		i++;
	}
	ft_push(tab, tabl, str, c);
	return (tab);
}
