#include "../include/nm.h"


int	ft_nm(void	*ptr, t_info info, char *name)
{
	int	magic;
	t_print	*print;	

	magic = *(int *)ptr;
	if (magic == MH_MAGIC)
	{
		if (name_sect_32(ptr, &info) == -1 || handle_32(ptr, &info) == -1)
			return (-1);
	}
	if (magic == MH_MAGIC_64)
	{
		if (name_sect_64(ptr, &info) == -1 || handle_64(ptr, &info) == -1)
			return (-1);
	}
	else if (magic ==  FAT_MAGIC || magic == FAT_CIGAM)
	{
		handle_fat(ptr, info, name);
		return (0);
	}
	print = info.print;
	print_nm(info.print, name);
	return (0);
}

char	*read_file(char *arg)
{
	int fd;
	void *ptr;
	struct stat buf;

	if ((fd = open(arg, O_RDONLY)) < 0)
		return NULL;
	if ((fstat(fd, &buf)) < 0)
		return NULL;
	if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return NULL;
	return ptr;
}

t_info	init_struct(void)
{
	t_info		info;

	info.section = NULL;
	info.print = NULL;
	return (info);
}

int	parse_one(char *name)
{
	t_info	info;
	void	*ptr;
	
	if (!(ptr = read_file(name)))
	{
		printf("ERROR FILE\n");
		return (-1);
	}
	info = init_struct();
	ft_nm(ptr, info, NULL);
	return (0);
}

int main(int argc, char **argv)
{
	void	*ptr;
	int	i;
	t_info	info;

	if (argc == 1)
		parse_one("a.out");
	else if (argc == 2)
		parse_one(argv[1]);
	else
	{
		i = 1;
		while (i <= argc - 1)
		{
			if (!(ptr = read_file(argv[i])))
				printf("ERROR FILE\n");
			else
			{
				info = init_struct();
				if (ft_nm(ptr, info, argv[i]) == -1)
					return (0);
			}
			i++;
		}
	}
	return (0);
}
