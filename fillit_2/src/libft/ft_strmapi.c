/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 14:32:56 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/26 15:51:24 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*s_new;
	unsigned int	i;

	if (s && f)
	{
		s_new = ft_memalloc((ft_strlen(s) + 1));
		if (!s_new)
			return (NULL);
		i = 0;
		while (s[i])
		{
			s_new[i] = f(i, s[i]);
			i++;
		}
		s_new[i] = '\0';
		return (s_new);
	}
	return (NULL);
}
