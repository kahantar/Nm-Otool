/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:12:48 by kahantar          #+#    #+#             */
/*   Updated: 2018/12/26 09:42:49 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nm.h"

int		free_map(void *ptr, int len)
{
	munmap(ptr, len);
	return (0);
}

void	free_info(t_info info)
{
	t_print	*print;
	t_print	*tmp_print;
	t_sec	*section;
	t_sec	*tmp_section;

	print = info.print;
	section = (t_sec*)info.section;
	while (print)
	{
		tmp_print = print->next;
		free(print);
		print = tmp_print;
	}
	while (section)
	{
		tmp_section = section->next;
		free(section);
		section = tmp_section;
	}
}

void	sort_ascii(t_print **print, t_print *tmp)
{
	t_print	*lst;

	lst = *print;
	if (!lst)
	{
		*print = tmp;
		return ;
	}
	if (ft_strcmp(lst->str, tmp->str) > 0)
	{
		tmp->next = lst;
		*print = tmp;
		return ;
	}
	while (lst->next)
	{
		if (ft_strcmp(lst->next->str, tmp->str) > 0)
		{
			tmp->next = lst->next;
			lst->next = tmp;
			return ;
		}
		lst = lst->next;
	}
	lst->next = tmp;
}
