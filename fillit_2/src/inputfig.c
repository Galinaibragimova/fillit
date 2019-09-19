/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:10:36 by mtonette          #+#    #+#             */
/*   Updated: 2019/09/19 19:07:12 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static	int		read_fromfile_to_str(int fd)
{
	int		count_ch;
	int		bytes;
	char	ch;

	count_ch = 0;
	while ((bytes = read(fd, &ch, 1)) > 0)
	{
		g_str_out[count_ch] = ch;
		count_ch++;
	}
	if (bytes == -1)
	{
		write(1, "error read file", 15);
		exit(1);
	}
	if (count_ch % 21 != 20)
		invalid_file();
	return (count_ch);
}

static	int		check_fig(int k, int i, int j)
{
	int is_true;
	int ii;

	is_true = 1;
	ii = 0;
	while (ii < 4)
	{
		if (g_in1[i + g_tm[k].fig[ii].dy][j + g_tm[k].fig[ii].dx] != '#')
		{
			is_true = 0;
			break ;
		}
		ii++;
	}
	if (is_true == 1)
		return (k);
	else
		return (-1);
}

static	int		detect_fig(void)
{
	int i;
	int j;
	int k;
	int numfig;

	k = 0;
	while (k < 19)
	{
		i = 0;
		while (i < 5 - g_tm[k].h)
		{
			j = 0;
			while (j < 5 - g_tm[k].w)
			{
				numfig = check_fig(k, i, j);
				if (numfig != -1)
					return (numfig);
				j++;
			}
			i++;
		}
		k++;
	}
	invalid_file();
	return (-1);
}

static	void	fill_block(void)
{
	int i;
	int j;
	int countcell;

	countcell = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((g_str_out[g_str_in] != '.') && (g_str_out[g_str_in] != '#'))
				invalid_file();
			if (g_str_out[g_str_in] == '#')
				countcell++;
			g_in1[i][j] = g_str_out[g_str_in];
			g_str_in++;
		}
		if (g_str_out[g_str_in] != '\n')
			invalid_file();
		g_str_in++;
	}
	if (countcell != 4)
		invalid_file();
}

int				input_tetriminos(int fd, int g_tin[26])
{
	int count_ch;
	int i;
	int j;
	int k;
	int n;

	templates(g_tm);
	i = 0;
	j = 0;
	count_ch = read_fromfile_to_str(fd);
	n = (count_ch + 1) / 21;
	if (n > 26)
		invalid_file();
	g_str_in = 0;
	k = -1;
	while (++k < n)
	{
		fill_block();
		if ((k != n - 1) && (g_str_out[g_str_in] != '\n'))
			invalid_file();
		g_str_in++;
		g_tin[k] = detect_fig();
	}
	close(fd);
	return (n);
}
