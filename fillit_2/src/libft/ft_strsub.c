/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:13:15 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/28 15:57:35 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*substr;
	size_t	i;

	substr = ft_memalloc(len + 1);
	if (!substr)
		return (NULL);
	if (s)
	{
		str = (char *)s;
		i = 0;
		while (i < len)
		{
			substr[i] = str[start + i];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
