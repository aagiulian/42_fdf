/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:04:27 by agiulian          #+#    #+#             */
/*   Updated: 2017/04/01 18:47:39 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_img(t_fdf *params)
{
	int bits_per_pixel;
	int size_line;
	int endian;

	params->img_ptr = mlx_new_image(params->mlx_ptr, WIDTH, HEIGHT);
	params->img_s = mlx_get_data_addr(params->img_ptr, &bits_per_pixel, \
			&size_line, &endian);
}

void		put_pxl_to_img(t_fdf *params, int x, int y, int colors)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	color;
	int				zero;

	x += params->mov_x;
	y += params->mov_y;
	if (x >= WIDTH / 2 || x <= WIDTH / -2 || y <= HEIGHT / -2 || y >= \
			HEIGHT / 2)
		return ;
	zero = 4 * WIDTH * HEIGHT / 2 + WIDTH / 2 * 4;
	color = mlx_get_color_value(params->mlx_ptr, colors);
	r = (color & 0XFF0000) >> 16;
	g = (color & 0XFF00) >> 8;
	b = (color & 0XFF);
	params->img_s[zero + 4 * WIDTH * y + x * 4] = r;
	params->img_s[zero + 4 * WIDTH * y + x * 4 + 1] = g;
	params->img_s[zero + 4 * WIDTH * y + x * 4 + 2] = b;
}

void		ft_bresenham(t_fdf *params, int tabxy[2], int x1, int y1)
{
	int		tabx[2];
	int		taby[2];
	int		e[2];
	int		x0;
	int		y0;

	x0 = tabxy[0];
	y0 = tabxy[1];
	tabx[0] = abs(x1 - x0);
	tabx[1] = x0 < x1 ? 1 : -1;
	taby[0] = abs(y1 - y0);
	taby[1] = y0 < y1 ? 1 : -1;
	e[0] = (tabx[0] > taby[0] ? tabx[0] : -taby[0]) / 2;
	while (x0 != x1 || y0 != y1)
	{
		put_pxl_to_img(params, x0, y0, params->color);
		e[1] = e[0];
		e[1] > -tabx[0] ? e[0] -= taby[0] : 1 == 1;
		e[1] > -tabx[0] ? x0 += tabx[1] : 1 == 1;
		e[1] < taby[0] ? e[0] += tabx[0] : 1 == 1;
		e[1] < taby[0] ? y0 += taby[1] : 1 == 1;
	}
}

static void	calcul_split(t_fdf *params, int i, int j, int tabxy[2])
{
	if (i + 1 < params->line)
		ft_bresenham(params, tabxy, (int)-(((sqrt(2.0) / 2) * ((i + 1) \
							- j) * params->z)), (int)-(((sqrt(2.0 / 3) * \
								(params->tab[i + 1][j] * params->d) - 1 \
								/ sqrt(6) * ((i + 1) + j)) * params->z)));
	if (j + 1 < params->col)
		ft_bresenham(params, tabxy, (int)-(((sqrt(2.0) / 2) * (i - (j + 1)) \
				* params->z)), (int)-(((sqrt(2.0 / 3) * (params->tab[i][j + 1] \
				* params->d) - 1 / sqrt(6) * (i + (j + 1))) * params->z)));
}

void		calcul(t_fdf *params)
{
	int		i;
	int		j;
	float	x;
	float	y;
	int		tabxy[2];

	create_img(params);
	i = 0;
	while (i < params->line)
	{
		j = 0;
		while (j < params->col)
		{
			tabxy[0] = (int)-((sqrt(2.0) / 2) * (i - j) * params->z);
			tabxy[1] = (int)-((sqrt(2.0 / 3) * (params->tab[i][j] * \
							params->d) - 1 / sqrt(6) * (i + j)) * params->z);
			calcul_split(params, i, j, tabxy);
			j++;
		}
		i++;
	}
}
