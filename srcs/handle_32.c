#include "../include/nm.h"

void    handle_32(void *ptr)
{
	struct mach_header *header;
	struct load_command *lc;
	int i;
	struct symtab_command *sym;



	header = (struct mach_header*)ptr;
	lc = (void*)ptr + sizeof(*header);
	i = 0;
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command*)lc;
			print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break;
		}
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
}
