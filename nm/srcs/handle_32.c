/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:17:26 by kahantar          #+#    #+#             */
/*   Updated: 2018/12/24 13:19:31 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nm.h"

int		get_info_32(struct symtab_command *sym, void *ptr, t_info *info)
{
	int				i;
	char			*string_table;
	struct nlist	*array;
	t_print			*print;
	t_print			*tmp;

	i = 0;
	print = NULL;
	string_table = ptr + sym->stroff;
	array = ptr + sym->symoff;
	while (i < sym->nsyms)
	{
		if (!(tmp = malloc(sizeof(t_print))))
			return (-1);
		tmp->str = string_table + array[i].n_un.n_strx;
		tmp->val = array[i].n_value;
		tmp->type = type(info, array[i].n_type, array[i].n_sect,\
					array[i].n_value);
		tmp->next = NULL;
		sort_ascii(&print, tmp);
		i++;
	}
	info->print = print;
	return (0);
}

int		handle_32(void *ptr, t_info *info)
{
	struct mach_header		*header;
	struct load_command		*lc;
	int						i;
	struct symtab_command	*sym;

	header = (struct mach_header*)ptr;
	lc = (void*)ptr + sizeof(*header);
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command*)lc;
			if (get_info_32(sym, ptr, info) == -1)
				return (-1);
		}
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
	return (0);
}
