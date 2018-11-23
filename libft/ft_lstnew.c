/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <kahantar@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 09:39:55 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:01:16 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;

	lst = NULL;
	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	lst->next = NULL;
	if (!content)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		lst->content_size = content_size;
		lst->content = ft_memalloc(content_size);
		ft_memcpy(lst->content, content, content_size);
	}
	return (lst);
}
