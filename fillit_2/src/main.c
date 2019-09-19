/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:10:36 by mtonette          #+#    #+#             */
/*   Updated: 2019/09/19 19:06:30 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		main(int argc, char *argv[])
{
	int fd;
	int i;
	int j;

	i = 0;
	j = 0;
	fd = check_openfile(argc, argv);
	templates(g_tm);
	g_p.n = input_tetriminos(fd, g_tin);
	g_totalcell = 4 * g_p.n;
	g_p.m = 2;
	while (g_p.m * g_p.m < g_totalcell)
		g_p.m++;
	g_p.permission = g_p.m * g_p.m - g_totalcell;
	g_a = newfield(g_p.m);
	while (start_perebor(g_a, g_tin, g_p) != 1)
	{
		freefield(g_a, g_p.m);
		g_p.m++;
		g_p.permission = g_p.m * g_p.m - g_totalcell;
		g_a = newfield(g_p.m);
	}
	print_res(g_a, g_p.m);
	freefield(g_a, g_p.m);
	return (0);
}
