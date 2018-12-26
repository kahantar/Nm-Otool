/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:23:22 by kahantar          #+#    #+#             */
/*   Updated: 2018/12/26 16:09:10 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nm.h"

t_print	*after_get(struct symtab_command *sym, struct nlist_64 *array,\
		t_info *info, char *string_table)
{
	int				i;
	t_print			*print;
	t_print			*tmp;
	int				start;

	print = NULL;
	i = 0;
	start = info->start;
	while (i < sym->nsyms)
	{
		info->start = start;
		if (!(tmp = malloc(sizeof(t_print))))
			return (NULL);
		if ((tmp->str = incrementing((void*)string_table, info,\
				array[i].n_un.n_strx, 0)) == NULL)
			return (NULL);
		tmp->val = array[i].n_value;
		tmp->type = type(info, array[i].n_type,\
			array[i].n_sect, array[i].n_value);
		tmp->next = NULL;
		sort_ascii(&print, tmp);
		i++;
	}
	return (print);
}

int		get_info_64(struct symtab_command *sym,\
		void *ptr, t_info *info, int start)
{
	int				i;
	char			*string_table;
	struct nlist_64	*array;
	t_print			*print;
	t_print			*tmp;

	i = 0;
	print = NULL;
	info->start = 0;
	if ((array = incrementing(ptr, info, sym->symoff, sizeof(array))) == NULL)
		return (-1);
	info->start = 0;
	if ((string_table = incrementing(ptr, info, sym->stroff,\
					sizeof(string_table))) == NULL)
		return (-1);
	if (!(info->print = after_get(sym, array, info, string_table)))
		return (-1);
	return (0);
}

int		handle_64(void *ptr, t_info *info)
{
	struct mach_header_64	*header;
	struct load_command		*lc;
	int						i;
	struct symtab_command	*sym;
	int						start;

	header = (struct mach_header_64*)ptr;
	info->start = 0;
	if ((lc = incrementing(ptr, info, sizeof(*header), sizeof(lc))) == NULL)
		return (-1);
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command*)lc;
			get_info_64(sym, ptr, info, start);
			return (0);
		}
		if ((lc = incrementing((void*)lc, info, lc->cmdsize,\
				sizeof(lc))) == NULL)
			return (-1);
		i++;
	}
	return (0);
}
