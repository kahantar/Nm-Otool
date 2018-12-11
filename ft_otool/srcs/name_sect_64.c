
#include "../include/otool.h"


int	parse_section_64(struct section_64 *section, t_info *info, char *ptr)
{
	int	i;
	int	y;
	size_t	addr;
	char	*str;
	
	addr = section->addr;
	str = ptr + section->offset;
	i = 0;
	y = 0;
	while (i < section->size)
	{
		if (y == 0)
		{
			ft_itoa_base(addr, 16);
			ft_putchar('\t');
		}
		ft_itoa_base((unsigned char)str[i], 0);
		ft_putchar(' ');
		i++;
		y++;
		if (y == 16 || i == section->size)
		{
			y = 0;
			ft_putchar('\n');
			addr = addr + 16;
		}
	}
	return (0);
}

int	parse_segment_64(void *lc, t_info *info, void *ptr)
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
		if (ft_strcmp(section->sectname, "__text") == 0 && ft_strcmp(section->segname, "__TEXT") == 0)
		{
			ft_putstr("Contents of (__TEXT,__text) section\n");
			if (parse_section_64(section, info, ptr) == -1)
				return (-1);
		}
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
			if (parse_segment_64(lc, info, ptr) == -1)
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
