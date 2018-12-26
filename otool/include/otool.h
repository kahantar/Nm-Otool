/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 10:04:52 by kahantar          #+#    #+#             */
/*   Updated: 2018/12/25 12:52:27 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include "../../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>

typedef struct			s_info
{
	struct s_print		*print;
	struct s_section	*section;
	int					len;
	int					start;
}						t_info;

typedef struct			s_print
{
	char				*str;
	unsigned char		type;
	unsigned long		val;
	struct s_print		*next;
}						t_print;

typedef struct			s_sec
{
	char				*str;
	struct s_sec		*next;
}						t_sec;

int						main(int argc, char **argv);
int						ft_otool(void *ptr, t_info info, char *name);
char					*read_file(char *arg, int *len);
int						handle_fat(void *ptr, t_info info, char *name);
int						name_sect_64(void *ptr, t_info *info);
void					ft_itoa_base(size_t n, int bit, int add);
int						name_sect_32(void *ptr, t_info *info);
void					*incrementing(void *ptr, t_info *info,\
							int nb, int size);
int						free_map(void *ptr, int len);

#endif
