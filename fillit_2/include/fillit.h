/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtonette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:43:20 by mtonette          #+#    #+#             */
/*   Updated: 2019/09/19 19:40:34 by mtonette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <fcntl.h>

# include "../src/libft/libft.h"

char			**g_a;
int				g_m;
int				g_count_hole;
int				g_tin[26];
char			g_str_out[550];
char			g_in1[4][4];
int				g_str_in;
int				g_n;
int				g_totalcell;
int				g_permission;

typedef	struct	s_nextcell
{
	int	dx;
	int	dy;
}				t_nextcell;

typedef	struct	s_tetriminos
{
	t_nextcell	fig[4];
	int			w;
	int			h;
}				t_tetriminos;

typedef	struct	s_param
{
	int	m;
	int	n;
	int	permission;
}				t_param;

t_tetriminos	g_tm[19];
t_param	g_p;

int				count_useless(char **a1, int m1);
int				input_tetriminos(int fd, int g_tin[26]);
int				start_perebor(char **a1, int tin1[], t_param p);
void			invalid_file();
char			**newfield(int g_m);
void			freefield(char **a, int g_m);
void			print_res(char **a, int g_m);
int				check_openfile(int argc, char *argv[]);
void			templates(t_tetriminos t[19]);

#endif
