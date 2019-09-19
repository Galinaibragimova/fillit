/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:09:26 by mtonette          #+#    #+#             */
/*   Updated: 2019/04/29 19:43:32 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_len_c_stop(const char *str, int start, char c_stop)
{
	size_t			counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[start] && str[start] != c_stop)
	{
		start++;
		counter++;
	}
	return (counter);
}

static int			ft_split_count(char const *s, char c)
{
	int				is_word;
	int				count_word;
	int				counter;
	char			*str;

	str = (char *)s;
	counter = 0;
	count_word = 0;
	while (str[counter])
	{
		is_word = 0;
		while ((str[counter] != (char)c) && str[counter + 1])
		{
			if (is_word == 0)
			{
				is_word = 1;
				count_word++;
			}
			counter++;
		}
		counter++;
	}
	return (count_word);
}

char				**ft_strsplit(char const *s, char c)
{
	int				count_word;
	int				i;
	unsigned int	counter;
	char			**mass_s;
	char			*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	counter = 0;
	count_word = ft_split_count(str, c);
	if (!(mass_s = (char**)ft_memalloc(sizeof(char**) * (count_word + 1))))
		return (NULL);
	i = 0;
	while (i < count_word)
	{
		while ((str[counter] == (char)c) && str[counter])
			counter++;
		mass_s[i] = ft_strsub(str, counter, ft_len_c_stop(str, counter, c));
		while ((str[counter] != (char)c) && str[counter])
			counter++;
		i++;
	}
	mass_s[i] = 0;
	return (mass_s);
}
