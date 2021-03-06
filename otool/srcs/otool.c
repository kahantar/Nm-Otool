/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 07:15:15 by kahantar          #+#    #+#             */
/*   Updated: 2018/12/26 16:45:48 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/otool.h"

int		ft_otool(void *ptr, t_info info, char *name)
{
	int	magic;

	magic = *(int *)ptr;
	if (magic == MH_MAGIC)
	{
		ft_putstr(name);
		ft_putstr(":\n");
		if (name_sect_32(ptr, &info) == -1)
			return (0);
	}
	if (magic == MH_MAGIC_64)
	{
		ft_putstr(name);
		ft_putstr(":\n");
		if (name_sect_64(ptr, &info) == -1)
			return (0);
	}
	else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
		handle_fat(ptr, info, name);
	return (0);
}

char	*read_file(char *arg, int *len)
{
	int			fd;
	void		*ptr;
	struct stat	buf;

	if ((fd = open(arg, O_RDONLY)) < 0)
		return (NULL);
	if ((fstat(fd, &buf)) < 0)
		return (NULL);
	if ((ptr = mmap(0, buf.st_size, PROT_READ,\
			MAP_PRIVATE, fd, 0)) == MAP_FAILED)
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
	ft_otool(ptr, info, NULL);
	munmap(ptr, len);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*ptr;
	int		i;
	t_info	info;
	int		len;

	if (argc == 1)
		parse_one("a.out");
	else
	{
		i = 1;
		while (i <= argc - 1)
		{
			if (!(ptr = read_file(argv[i], &len)))
				ft_putstr("ERROR FILE\n");
			else
			{
				info = init_struct(len);
				if (ft_otool(ptr, info, argv[i]) == -1)
					return (free_map(ptr, len));
				munmap(ptr, len);
			}
			i++;
		}
	}
	return (0);
}
