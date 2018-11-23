#include "../include/nm.h"

int	get_info_64(struct symtab_command *sym, void *ptr, t_info *info)
{
	int		i;
	char		*string_table;
	struct nlist_64 *array;
	t_print		*print;
	t_print		*tmp;

	i = 0;
	if (!(print = malloc(sizeof(t_print))))
		return 0;
	tmp = print;
	tmp->next = NULL;
	string_table = ptr + sym->stroff;
	array = ptr + sym->symoff;
	while (i < sym->nsyms)
	{
		tmp->str = string_table + array[i].n_un.n_strx;
		tmp->val = array[i].n_value;
		tmp->type = type(info, array[i].n_type, array[i].n_sect, array[i].n_value);
		if (i == sym->nsyms - 1)
			tmp->next = NULL;
		else
		{
			if (!(tmp->next = malloc(sizeof(t_print))))
				return 0;
		}	
		tmp = tmp->next;
		i++;
	}
	info->print = print;
	return 1;
}

int	handle_64(void *ptr, t_info *info)
{
	struct mach_header_64 *header;
	struct load_command *lc;
	int i;
	struct symtab_command *sym;

	header = (struct mach_header_64*)ptr;
	lc = (void*)ptr + sizeof(*header);
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command*)lc;
			get_info_64(sym, ptr, info);
		}
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
}
