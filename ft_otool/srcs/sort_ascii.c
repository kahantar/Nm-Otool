
#include "../include/otool.h"

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
