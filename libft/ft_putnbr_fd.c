/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:36:48 by kahantar          #+#    #+#             */
/*   Updated: 2017/03/29 20:02:19 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	long	i;

	i = n;
	if (i == 0)
		ft_putchar_fd(48, fd);
	if (i < 0 && i >= -2147483648)
	{
		ft_putchar_fd('-', fd);
		i = -i;
	}
	if (i >= 10 && i <= 2147483648)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
	if (i > 0 && i < 10)
	{
		ft_putchar_fd('0' + i, fd);
	}
}
