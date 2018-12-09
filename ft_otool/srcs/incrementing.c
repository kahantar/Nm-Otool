
#include "../include/otool.h"

void		*incrementing(void *ptr, t_info *info, int nb, int size)
{
	void	*ret;
	if (info->start + nb + size > info->len)
		return (NULL);
	info->start = info->start + nb;
	ret = ptr + nb;
	//printf("%d\n", info->start);
	return (ret);
}

