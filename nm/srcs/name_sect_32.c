/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_sect_32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:35:01 by kahantar          #+#    #+#             */
/*   Updated: 2018/12/26 16:09:09 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nm.h"

int		parse_section(struct section *section, t_info *info)
{
	t_sec	*info_section;
	t_sec	*sect;

	sect = (t_sec*)info->section;
	if (!(info_section = malloc(sizeof(t_sec))))
		return (-1);
	info_section->str = section->sectname;
	info_section->next = NULL;
	if (sect == NULL)
	{
		sect = (t_sec*)info_section;
		info->section = (struct s_section *)sect;
	}
	else
	{
		while (sect->next)
			sect = sect->next;
		sect->next = info_section;
	}
	return (0);
}

int		parse_segment(void *lc, t_info *info)
{
	struct segment_command	*segment;
	struct section			*section;
	int						i;

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

int		name_sect_32(void *ptr, t_info *info)
{
	struct mach_header	*header;
	struct load_command	*lc;
	int					i;
	t_sec				*s;

	i = 0;
	header = ptr;
	if ((lc = incrementing(ptr, info, sizeof(*header), sizeof(lc))) == NULL)
		return (-1);
	while (i < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			if ((parse_segment(lc, info)))
				return (-1);
		if ((lc = incrementing((void*)lc, info, lc->cmdsize,\
				sizeof(lc))) == NULL)
			return (-1);
		i++;
	}
	info->start = 0;
	s = (t_sec*)info->section;
	return (0);
}
