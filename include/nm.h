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
	unsigned char	type;
	unsigned long	val;
	struct s_print	*next;
}			t_print;

typedef struct s_sec {
	char			*str;
	struct s_sec	*next;
}			t_sec;

int	main(int argc, char **argv);
int    ft_nm(void *ptr, t_info info, char *name);
char    *read_file(char *arg);
void    handle_fat(void *ptr, t_info info, char *name);
int	handle_64(void *ptr, t_info *info);
int    handle_32(void *ptr, t_info *info);
int	name_sect_64(void *ptr, t_info *info);
unsigned char	type(t_info *info, unsigned char c, unsigned char n, unsigned long val);
void	sort_ascii(t_print **print, t_print *tmp);
void	print_nm(t_print *print, char *name);
void    ft_itoa_base(unsigned long n, int base);
int	name_sect_32(void *ptr, t_info *info);


#endif
