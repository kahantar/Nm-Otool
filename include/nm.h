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

typedef struct s_print {
	char		*str;
	char		c;
	struct s_print	*next;
}			t_print;

void    ft_nm(void *ptr);
char    *read_file(char *arg);
void    handle_fat(void *ptr);
void    handle_64(void *ptr);
void    handle_32(void *ptr);

#endif
