#include "../include/nm.h"

int	get_info_64(struct symtab_command *sym, void *ptr, t_info *info)
{
	int		i;
	char		*string_table;
	struct nlist_64 *array;
	t_print		*print;
	t_print		*tmp;
	int		start
;
	i = 0;
	print = NULL;
	info->start = 0;
	if ((array = incrementing(ptr, info, sym->symoff, sizeof(array))) == NULL)
		return (-1);
	info->start = 0;
	if ((string_table = incrementing(ptr, info, sym->stroff, sizeof(string_table))) == NULL)
		return (-1);
	start = info->start;
	//string_table = ptr + sym->stroff;
	//array = ptr + sym->symoff;
	while (i < sym->nsyms)
	{
		info->start = start;
		if (!(tmp = malloc(sizeof(t_print))))
			return (-1);
		if ((tmp->str = incrementing((void*)string_table, info, array[i].n_un.n_strx, 0)) == NULL)
			return (-1);
		//tmp->str = string_table + array[i].n_un.n_strx;
		tmp->val = array[i].n_value;
		tmp->type = type(info, array[i].n_type, array[i].n_sect, array[i].n_value);
		tmp->next = NULL;
		sort_ascii(&print, tmp);
		i++;
	}
	info->print = print;
	return (0);
}

int	handle_64(void *ptr, t_info *info)
{
	struct mach_header_64 *header;
	struct load_command *lc;
	int i;
	struct symtab_command *sym;

	header = (struct mach_header_64*)ptr;
	if ((lc = incrementing(ptr, info, sizeof(*header), sizeof(lc))) == NULL)
		return (-1);
//	lc = (void*)ptr + sizeof(*header);
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command*)lc;
			get_info_64(sym, ptr, info);
			return (0);
		}
		if ((lc = incrementing((void*)lc, info, lc->cmdsize, sizeof(lc))) == NULL)
			return (-1);
	//	lc = (void*)lc + lc->cmdsize;
		i++;
	}
	return (0);
}
