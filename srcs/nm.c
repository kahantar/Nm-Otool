#include "../include/nm.h"


void	ft_nm(void	*ptr, t_info info)
{
	int	magic;
	t_section	*print;

	magic = *(int *)ptr;
//	if (magic == MH_MAGIC)
//		handle_32(ptr);
	if (magic == MH_MAGIC_64)
	{
		name_sect_64(ptr, &info);
		handle_64(ptr, &info);
	}
	else if (magic ==  FAT_MAGIC || magic == FAT_CIGAM)
		handle_fat(ptr, info);
	print = info.section;
	while (print)
	{
		printf("%s\n", print->str);
		print = print->next;
	}
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

int main(int argc, char **argv)
{
	void	*ptr;
	int	i;
	t_info	info;
	
	i = 1;
	while (i <= argc - 1)
	{
		if (argc == 1)
		{
			if (!(ptr = read_file("a.aout")))
			{
				printf("ERROR FILE\n");
				return (0);
			}
		}
		else
		{
			if (!(ptr = read_file(argv[i])))
			{
				printf("ERROR FILE\n");
				return (0);
			}
			info = init_struct();
			ft_nm(ptr, info);
		}
		i++;
	}
	return (0);
}
