/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:47:21 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/29 18:00:05 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int left;
	unsigned int right;

	left = 0;
	if (s)
	{
		while (s[left] == ' ' || s[left] == '\t' || s[left] == '\n')
			left++;
		if (s[left] == '\0')
			return (ft_strnew(0));
		right = left;
		while (s[right] != '\0')
			right++;
		right--;
		while (s[right] == ' ' || s[right] == '\t' || s[right] == '\n')
			right--;
		return (ft_strsub(s, left, right - left + 1));
	}
	return (NULL);
}
