/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:43:08 by kahantar          #+#    #+#             */
/*   Updated: 2018/12/26 09:42:57 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nm.h"

int		ft_nm(void *ptr, t_info info, char *name)
{
	int		magic;
	t_print	*print;
	int		bit;

	magic = *(int *)ptr;
	if (magic == MH_MAGIC)
	{
		if (name_sect_32(ptr, &info) == -1 || handle_32(ptr, &info) == -1)
			return (-1);
		bit = 8;
	}
	if (magic == MH_MAGIC_64)
	{
		if (name_sect_64(ptr, &info) == -1 || handle_64(ptr, &info) == -1)
			return (-1);
		bit = 16;
	}
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
	{
		handle_fat(ptr, info, name);
		return (0);
	}
	print_nm(info.print, name, bit);
	free_info(info);
	return (0);
}

char	*read_file(char *arg, int *len)
{
	int			fd;
	void		*ptr;
	struct stat buf;

	if ((fd = open(arg, O_RDONLY)) < 0)
		return (NULL);
	if ((fstat(fd, &buf)) < 0)
		return (NULL);
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE,\
		fd, 0)) == MAP_FAILED)
		return (NULL);
	*len = buf.st_size;
	return (ptr);
}

t_info	init_struct(int len)
{
	t_info		info;

	info.section = NULL;
	info.print = NULL;
	info.len = len;
	info.start = 0;
	return (info);
}

int		parse_one(char *name)
{
	t_info	info;
	void	*ptr;
	int		len;

	if (!(ptr = read_file(name, &len)))
	{
		ft_putstr("ERROR FILE\n");
		return (-1);
	}
	info = init_struct(len);
	ft_nm(ptr, info, NULL);
	munmap(ptr, len);
	return (0);
}

int		main(int argc, char **argv)
{
	void		*ptr;
	int			i;
	t_info		info;
	int			len;

	(argc == 1) ? parse_one("a.out") : 0;
	(argc == 2) ? parse_one(argv[1]) : 0;
	if (argc > 2)
	{
		i = 0;
		while (++i <= argc - 1)
		{
			if (!(ptr = read_file(argv[i], &len)))
				ft_putstr("ERROR FILE\n");
			else
			{
				info = init_struct(len);
				if (ft_nm(ptr, info, argv[i]) == -1)
					free_map(ptr, len);
				munmap(ptr, len);
			}
		}
	}
	return (0);
}
