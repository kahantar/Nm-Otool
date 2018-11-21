#include "../include/nm.h"

t_print	*print_output(struct symtab_command *sym, void *ptr)
{
	int		i;
	char		*string_table;
	struct nlist_64 *array;
	t_print		*print;
	t_print		*tmp;

	i = 0;
	if (!(print = malloc(sizeof(t_print))))
		return NULL;
	tmp = print;
	tmp->next = NULL;
	string_table = ptr + sym->stroff;
	array = ptr + sym->symoff;
	while (i < sym->nsyms)
	{
		tmp->str = string_table + array[i].n_un.n_strx;
		printf("%x  %s\n", string_table + array[i].n_value, tmp->str);
		if (i == sym->nsyms - 1)
			tmp->next = NULL;
		else
		{
			if (!(tmp->next = malloc(sizeof(t_print))))
				return NULL;
		}	
		tmp = tmp->next;
		i++;
	}
	return (print);
}

t_print	*handle_64(void *ptr)
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
			return (print_output(sym, ptr));
		}
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
	return (NULL);
}
