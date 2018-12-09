
#include "../include/nm.h"

void		*incrementing(void *ptr, t_info *info, int nb, int size)
{
	void	*ret;
	if (info->start + nb + size > info->len)
		return (NULL);
	info->start = info->start + nb;
	ret = ptr + nb;
	//printf("%d\n", info->start);
	return (ret);
}

unsigned char	search_in_sect(t_info *info, unsigned char n)
{
	t_sec	*section;
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
		i++;
		section = section->next;	
	}
}

unsigned char	type(t_info *info, unsigned char c, unsigned char n, unsigned long val)
{
	unsigned char x;

	x = c;
	if ((c & N_TYPE) == N_UNDF)
	{
		x = 'u';
		if (val != 0)
			x = 'c';
	}
	else if ((c & N_TYPE) == N_PBUD)
		x = 'u';
	else if ((c & N_TYPE) == N_ABS)
		x = 'a';
	else if ((c & N_TYPE) == N_SECT)
		x = search_in_sect(info, n);
	else if ((c & N_TYPE) == N_INDR)
		x = 'i';
	else
		x = '?';
	if ((c & N_EXT) && x != '?')
		x = ft_toupper(x);
	return (x);
}

