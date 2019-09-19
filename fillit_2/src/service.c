/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:10:36 by mtonette          #+#    #+#             */
/*   Updated: 2019/09/19 19:09:09 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void	invalid_file(void)
{
	write(1, "error", 5);
	exit(1);
}

int		check_openfile(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
	{
		write(1, "error num parameters", 19);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "error open file", 15);
		exit(1);
	}
	return (fd);
}

char	**newfield(int g_m)
{
	int		i;
	int		j;
	char	**g_a;

	g_a = (char **)malloc(g_m * sizeof(char *));
	i = 0;
	while (i < g_m)
	{
		g_a[i] = (char *)malloc(g_m * sizeof(char));
		i++;
	}
	i = 0;
	while (i < g_m)
	{
		j = 0;
		while (j < g_m)
		{
			g_a[i][j] = '.';
			j++;
		}
		i++;
	}
	return (g_a);
}

void	freefield(char **g_a, int g_m)
{
	int i;

	i = 0;
	while (i < g_m)
	{
		free(g_a[i]);
		i++;
	}
	free(g_a);
}

void	print_res(char **g_a, int g_m)
{
	int i;
	int j;

	i = -1;
	while (++i < g_m)
	{
		j = -1;
		while (++j < g_m)
		{
			write(1, &g_a[i][j], 1);
		}
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}
