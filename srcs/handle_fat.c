#include "../include/nm.h"

int     swap_bit(int nb)
{
    int ret;

    ret = 0;
    ret = ((nb & 0xFF000000) >> 24) | ret;
    ret = ((nb & 0x00FF0000) >> 8) | ret;
    ret = ((nb & 0x0000FF00) << 8) | ret;
    ret = ((nb & 0x000000FF) << 24) | ret;
    return (ret);
}

void    handle_fat(void *ptr)
{
    struct fat_header *header;
    int     nb_arch;

    header = ptr;
    nb_arch = swap_bit(header->nfat_arch);
    printf("%x\n", nb_arch);
}