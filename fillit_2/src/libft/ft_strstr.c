/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:37:45 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/24 19:50:37 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			j;
	const char	*h;

	i = 0;
	h = haystack;
	if (!*needle)
		return ((char*)haystack);
	while (h[i])
	{
		j = 0;
		while (h[i + j] == needle[j])
		{
			if (!needle[j + 1])
				return ((char*)h + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
