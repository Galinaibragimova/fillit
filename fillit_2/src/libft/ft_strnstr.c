/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:37:45 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/24 19:48:38 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		i;
	size_t		j;
	const char	*h;

	h = haystack;
	i = 0;
	if (!*needle)
		return ((char*)h);
	while (h[i])
	{
		j = 0;
		while (h[i + j] == needle[j] && (i + j) < n)
		{
			if (!needle[j + 1])
				return ((char*)h + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
