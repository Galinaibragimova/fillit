/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:10:36 by mtonette          #+#    #+#             */
/*   Updated: 2019/09/18 20:07:06 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static	void	cleaner(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_m)
	{
		j = 0;
		while (j < g_m)
		{
			if (g_a[i][j] == '-')
				g_a[i][j] = '.';
			j++;
		}
		i++;
	}
}

static	void	c_hole(int s, int c)
{
	g_a[s][c] = '-';
	g_count_hole++;
	if (c > 0 && (g_a[s][c - 1] == '.'))
		c_hole(s, c - 1);
	if (c < g_m - 1 && (g_a[s][c + 1] == '.'))
		c_hole(s, c + 1);
	if (s > 0 && (g_a[s - 1][c] == '.'))
		c_hole(s - 1, c);
	if (s < g_m - 1 && (g_a[s + 1][c] == '.'))
		c_hole(s + 1, c);
}

int				count_useless(char **a1, int m1)
{
	int i;
	int j;
	int useless;

	i = 0;
	useless = 0;
	g_a = a1;
	g_m = m1;
	while (i < g_m)
	{
		j = 0;
		while (j < g_m)
		{
			if (g_a[i][j] == '.')
			{
				g_count_hole = 0;
				c_hole(i, j);
				useless += g_count_hole % 4;
			}
			j++;
		}
		i++;
	}
	cleaner();
	return (useless);
}
