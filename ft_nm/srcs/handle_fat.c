#include "../include/nm.h"

int     swap_bit(int nb)
{
    int ret;

    ret = ((nb & 0xFF000000) >> 24);
    ret = ((nb & 0x00FF0000) >> 8) | ret;
    ret = ((nb & 0x0000FF00) << 8) | ret;
    ret = ((nb & 0x000000FF) << 24) | ret;
    return (ret);
}

int    handle_fat(void *ptr, t_info info, char *name)
{
	struct fat_header	*header;
	int			nb_arch;
	struct fat_arch		*arch;
	int			i;
	
	if ((arch = incrementing(ptr, &info, sizeof(header), sizeof(arch))) == NULL)
		return (-1);
	//arch = ptr + sizeof(header);
	i = 0;
	header = ptr;
	nb_arch = swap_bit(header->nfat_arch);
	while (i < nb_arch)
	{
		if (swap_bit(arch->cputype) == CPU_TYPE_X86_64)
			ft_nm(ptr + swap_bit(arch->offset), info, name);
		if ((arch = incrementing((void*)arch, &info, sizeof(arch), sizeof(arch))) == NULL)
			return (-1);
		//arch = (void*)arch + sizeof(arch);
		i++;	
	}
	return (0);
}