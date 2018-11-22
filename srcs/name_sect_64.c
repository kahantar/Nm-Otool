
#include "../include/nm.h"

int	parse_section_64(struct section_64 *section, t_info *info)
{
	t_section	*info_section;
	
	if (!(info_section = malloc(sizeof(t_section))))
		return (0);
	info_section->str = section->sectname;
	info_section->next = NULL;
	if (info->section == NULL)
		info->section = info_section;
	else
	{
		while (info->section->next)
			info->section = info->section->next;
		info->section->next = info_section;
		printf("%s\n", info->section->next->str);
	}
	return (1);
}

int	parse_segment_64(void *lc, t_info *info)
{
	struct segment_command_64	*segment;
	struct section_64		*section;
	int				i;

	i = 0;
	segment = lc;
	section = (void*)segment + sizeof(*segment);
	while (i < segment->nsects)
	{
		parse_section_64(section, info);
		section = (void*)section + sizeof(*section);
		i++;
	}
	return (1);	
}

int	name_sect_64(void *ptr, t_info *info)
{
	struct mach_header_64 *header;
	struct load_command *lc;
	int			i;

	i = 0;
	header = ptr;
	lc = ptr + sizeof(*header);
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			parse_segment_64(lc, info);	
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
	return (1);	
}
