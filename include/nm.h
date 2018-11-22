#ifndef NM_h
# define NM_h

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h> 
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>

typedef struct s_info	{
	struct s_print		*print;
	struct s_section	*section;
}			t_info;

typedef struct s_print {
	char		*str;
	char		c;
	unsigned long	val;
	struct s_print	*next;
}			t_print;

typedef struct s_section {
	char			*str;
	struct s_section	*next;
}			t_section;

void    ft_nm(void *ptr, t_info info);
char    *read_file(char *arg);
void    handle_fat(void *ptr, t_info info);
int	handle_64(void *ptr, t_info *info);
void    handle_32(void *ptr);
int	name_sect_64(void *ptr, t_info *info);

#endif
