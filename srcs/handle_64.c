#include "../include/nm.h"

void*	print_output(struct symtab_command *sym, void *ptr)
{
	int		i;
	char		*string_table;
	struct nlist_64 *array;
	t_print		*print;
	t_print		*tmp;

	i = 0;
	if (!(print = malloc(sizeof(t_print*))))
		return NULL;
	tmp = print;
			tmp->next = NULL;
	string_table = ptr + sym->stroff;
	array = ptr + sym->symoff;
	while (i < sym->nsyms)
	{
		tmp->str = string_table + array[i].n_un.n_strx;
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
	while (print)
	{
		printf("%s\n", print->str);
		print = print->next;
	}
	return NULL;
}

void    handle_64(void *ptr)
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
			print_output(sym, ptr);
			break;
		}
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
}
