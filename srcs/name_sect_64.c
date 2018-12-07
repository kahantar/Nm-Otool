
#include "../include/nm.h"

int	parse_section_64(struct section_64 *section, t_info *info)
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

int	parse_segment_64(void *lc, t_info *info)
{
	struct segment_command_64	*segment;
	struct section_64		*section;
	int				i;

	i = 0;
	segment = lc;
	if ((section = incrementing((void*)segment, info, sizeof(*segment), sizeof(section))) == NULL)
		return (-1);
	//section = (void*)segment + sizeof(*segment);
	while (i < segment->nsects)
	{
		if (parse_section_64(section, info) == -1)
			return (-1);
		if ((section = incrementing((void*)section, info, sizeof(*section), sizeof(section))) == NULL)
			return (-1);
		//section = (void*)section + sizeof(*section);
		i++;
	}
	return (0);	
}

int	name_sect_64(void *ptr, t_info *info)
{
	struct mach_header_64 *header;
	struct load_command *lc;
	int			i;

	i = 0;
	header = ptr;
	if ((lc = incrementing(ptr, info, sizeof(*header), sizeof(lc))) == NULL)
		return (-1);
	//lc = ptr + sizeof(*header);
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			if (parse_segment_64(lc, info) == -1)
				return (-1);
		}
		if ((lc = incrementing((void*)lc, info, lc->cmdsize, sizeof(lc))) == NULL)
			return (-1);
	//	lc = (void*)lc + lc->cmdsize;
		i++;
	}
	info->start = 0;
	return (0);	
}
