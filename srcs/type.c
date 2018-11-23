
#include "../include/nm.h"

unsigned char	search_in_sect(t_info *info, unsigned char n)
{
	t_section	*section;
	unsigned char	i;

	section = info->section;
	i = 1;
	while (section)
	{
		if (i == n)
		{
			if(!ft_strcmp(section->str, "__text"))
				return ('t');
			else if (!ft_strcmp(section->str, "__data"))
				return ('d');
			else if (!ft_strcmp(section->str, "__bss"))
				return ('b');
			else
				return ('s');
		}
		section = section->next;	
	}
}

unsigned char	type(t_info *info, unsigned char c, unsigned char n, unsigned long val)
{
	if ((c & N_TYPE) == N_UNDF)
	{
		c = 'u';
		if (val != 0)
			c = 'c';
	}
	else if ((c & N_TYPE) == N_PBUD)
		c = 'u';
	else if ((c & N_TYPE) == N_ABS)
		c = 'a';
	else if ((c & N_TYPE) == N_SECT)
		c = search_in_sect(info, n);
	else if ((c & N_TYPE) == N_INDR)
		c = 'i';
	else
		c = '?';
	return (c);
}
