/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:49:06 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/29 19:28:44 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_unchar(unsigned char c, int fd)
{
	unsigned char	octet1;
	unsigned char	octet2;
	unsigned char	unchar;

	unchar = (129 + c) + 127;
	octet1 = unchar >> 6;
	octet1 = octet1 ^ 192;
	unchar = unchar << 2;
	unchar = unchar >> 2;
	octet2 = 128 ^ unchar;
	write(fd, &octet1, 1);
	write(fd, &octet2, 1);
	return (0);
}

void			ft_putchar_fd(char c, int fd)
{
	if (c < 0)
		ft_unchar(c, fd);
	else
		write(fd, &c, 1);
}
