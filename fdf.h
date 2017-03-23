/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:20:01 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/23 19:55:32 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h> // penser a enlever
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft/includes/libft.h"
# include "libft/libft/includes/get_next_line.h"
# include "libft/printf/ft_printf.h"

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		col;
	int		line;
	int		**tab;
}				t_fdf;

int				ft_commands(int keycode, t_fdf *params);
int				ft_parse_map(t_fdf *params, char *file);

#endif
