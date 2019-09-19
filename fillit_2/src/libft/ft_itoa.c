/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 17:38:22 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/28 17:52:29 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		size;
	int		negative;
	int		tmp;
	char	*mass;

	negative = 0;
	if (n < 0)
		negative = 1;
	tmp = n;
	size = 1;
	while (tmp /= 10)
		size++;
	mass = ft_strnew(size + negative);
	if (mass == NULL)
		return (NULL);
	if (negative)
		mass[0] = '-';
	while (size--)
	{
		mass[size + negative] = (negative ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (mass);
}
