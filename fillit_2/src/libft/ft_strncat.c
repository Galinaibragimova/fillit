/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:37:13 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/24 19:37:17 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char			*ss1;
	const char		*ss2;
	size_t			i;
	size_t			j;

	ss1 = s1;
	ss2 = s2;
	i = 0;
	j = 0;
	while (ss1[i] != '\0')
		i++;
	while (ss2[j] != '\0' && j < n)
	{
		ss1[i + j] = ss2[j];
		j++;
	}
	ss1[i + j] = '\0';
	return (ss1);
}
