/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:43:54 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/24 16:49:37 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*a;

	a = (char*)b;
	i = 0;
	if (len == 0)
		return (a);
	{
		while (i < len)
		{
			a[i] = (unsigned char)c;
			i++;
		}
		return (b);
	}
}
