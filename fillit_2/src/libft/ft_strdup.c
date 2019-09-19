/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:25:58 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/29 19:07:39 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*d_s1;

	i = 0;
	d_s1 = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (d_s1 == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		d_s1[i] = s1[i];
		i++;
	}
	d_s1[i] = s1[i];
	return (d_s1);
}
