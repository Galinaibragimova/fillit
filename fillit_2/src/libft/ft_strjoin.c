/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:59:46 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/29 16:09:05 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_sum;

	if (s1 && s2)
	{
		str_sum = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (!str_sum)
			return (NULL);
		str_sum = ft_strcpy(str_sum, s1);
		str_sum = ft_strcat(str_sum, s2);
		return (str_sum);
	}
	return (NULL);
}
