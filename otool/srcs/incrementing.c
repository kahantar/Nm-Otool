/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incrementing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:41:22 by kahantar          #+#    #+#             */
/*   Updated: 2018/12/25 10:01:44 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/otool.h"

int			free_map(void *ptr, int len)
{
	munmap(ptr, len);
	return (0);
}

void		*incrementing(void *ptr, t_info *info, int nb, int size)
{
	void	*ret;

	if (info->start + nb + size > info->len)
		return (NULL);
	info->start = info->start + nb;
	ret = ptr + nb;
	return (ret);
}
