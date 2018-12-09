
#include "../include/nm.h"

int	parse_section(struct section *section, t_info *info)
{
	t_sec	*info_section;
	t_sec	*sect;
	
	sect = info->section;
	if (!(info_section = malloc(sizeof(t_sec))))
		return (-1);
	info_section->str = section->sectname;
	info_section->next = NULL;
	if (sect == NULL){
		sect = info_section;
		info->section = sect;
	}
	else
	{
		while (sect->next)
			sect = sect->next;
		sect->next = info_section;
	}
	return (0);
}

int	parse_segment(void *lc, t_info *info)
{
	struct segment_command	*segment;
	struct section		*section;
	int				i;

	i = 0;
	segment = lc;
	section = (void*)segment + sizeof(*segment);
	while (i < segment->nsects)
	{
		if (parse_section(section, info) == -1)
			return (-1);
		section = (void*)section + sizeof(*section);
		i++;
	}
	return (0);	
}

int	name_sect_32(void *ptr, t_info *info)
{
	struct mach_header *header;
	struct load_command *lc;
	int			i;
	t_sec *s;

	i = 0;
	header = ptr;
	if ((lc = incrementing(ptr, info, sizeof(*header), sizeof(lc))) == NULL)
		return (-1);
	//lc = ptr + sizeof(*header);
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			if (parse_segment(lc, info) == -1)
				return (-1);
		}			
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
	s = info->section;
	return (0);	
}