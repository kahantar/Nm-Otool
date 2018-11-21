#include "../include/nm.h"

void	ft_nm(void	*ptr)
{
	int	magic;
	t_print	*print;
	magic = *(int *)ptr;
//	printf("%x\n", magic);
//	if (magic == MH_MAGIC)
//		handle_32(ptr);
	 if (magic == MH_MAGIC_64)
		print = handle_64(ptr);
	else if (magic ==  FAT_MAGIC || magic == FAT_CIGAM)
		handle_fat(ptr);	
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

int main(int argc, char **argv)
{
	void *ptr;
	int i;
	
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
			ft_nm(ptr);
		}
		i++;
	}
	return (0);
}
