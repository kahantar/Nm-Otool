/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_sect_32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:42:20 by kahantar          #+#    #+#             */
/*   Updated: 2018/12/26 10:44:15 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/otool.h"

void	parse_section_32(struct section *section, t_info *info, char *ptr)
{
	int		i;
	int		y;
	size_t	addr;
	char	*str;

	addr = section->addr;
	str = ptr + section->offset;
	i = -1;
	y = 0;
	while (++i < section->size)
	{
		if (y == 0)
		{
			ft_itoa_base(addr, 8, 0);
			ft_putchar('\t');
		}
		ft_itoa_base((unsigned char)str[i], 0, 1);
		ft_putchar(' ');
		if (++y == 16 || i == section->size - 1)
		{
			y = 0;
			ft_putchar('\n');
			addr = addr + 16;
		}
	}
}

int		parse_segment_32(void *lc, t_info *info, void *ptr)
{
	struct segment_command	*segment;
	struct section			*section;
	int						i;

	i = 0;
	segment = lc;
	if ((section = incrementing((void*)segment,\
			info, sizeof(*segment), sizeof(section))) == NULL)
		return (-1);
	while (i < segment->nsects)
	{
		if (ft_strcmp(section->sectname, "__text") == 0 &&\
			ft_strcmp(section->segname, "__TEXT") == 0)
		{
			ft_putstr("Contents of (__TEXT,__text) section\n");
			parse_section_32(section, info, ptr);
		}
		if ((section = incrementing((void*)section, info,\
				sizeof(*section), sizeof(section))) == NULL)
			return (-1);
		i++;
	}
	return (0);
}

int		name_sect_32(void *ptr, t_info *info)
{
	struct mach_header	*header;
	struct load_command	*lc;
	int					i;

	i = 0;
	header = ptr;
	if ((lc = incrementing(ptr, info, sizeof(*header), sizeof(lc))) == NULL)
		return (-1);
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			if (parse_segment_32(lc, info, ptr) == -1)
				return (-1);
		}
		if ((lc = incrementing((void*)lc, info,\
				lc->cmdsize, sizeof(lc))) == NULL)
			return (-1);
		i++;
	}
	info->start = 0;
	return (0);
}
