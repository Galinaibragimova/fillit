/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:10:36 by mtonette          #+#    #+#             */
/*   Updated: 2019/09/19 19:08:36 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static	int		is_free(int s, int c, int k)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_a[s + g_tm[k].fig[i].dy][c + g_tm[k].fig[i].dx] != '.')
			return (0);
		i++;
	}
	return (1);
}

static	void	fill_fig(int s, int c, int k, char b)
{
	int i;

	i = 0;
	while (i < 4)
	{
		g_a[s + g_tm[k].fig[i].dy][c + g_tm[k].fig[i].dx] = b;
		i++;
	}
}

static	int		perebor(int k)
{
	int c;
	int s;

	s = -1;
	while (++s <= (g_m - g_tm[g_tin[k]].h))
	{
		c = -1;
		while (++c <= (g_m - g_tm[g_tin[k]].w))
		{
			if (is_free(s, c, g_tin[k]) == 1)
			{
				fill_fig(s, c, g_tin[k], 'A' + k);
				if (count_useless(g_a, g_m) > g_permission)
				{
					fill_fig(s, c, g_tin[k], '.');
					continue;
				}
				if (k == g_n - 1 || perebor(k + 1) == 1)
					return (1);
				fill_fig(s, c, g_tin[k], '.');
			}
		}
	}
	return (0);
}

int				start_perebor(char **a1, int tin1[], t_param g_p)
{
	int i;

	i = 0;
	g_a = a1;
	g_m = g_p.m;
	g_n = g_p.n;
	templates(g_tm);
	while (i < g_n)
	{
		g_tin[i] = tin1[i];
		i++;
	}
	g_permission = g_p.permission;
	return (perebor(0));
}
