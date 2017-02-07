/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:20:01 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/07 18:38:30 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_fdf;

int				ft_commands(int keycode, t_fdf *params);

#endif
