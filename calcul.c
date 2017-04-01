/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:04:27 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/31 14:08:16 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_img(t_fdf *params)
{
	int bits_per_pixel;
	int size_line;
	int endian;

	params->img_ptr = mlx_new_image(params->mlx_ptr, 800, 600);
	params->img_s = mlx_get_data_addr(params->img_ptr, &bits_per_pixel, &size_line, &endian);
	ft_printf("size line = %i\n", size_line);
	ft_printf("bpp = %i\n", bits_per_pixel);
	ft_printf("endian = %i\n", endian);

}

void	put_pxl_to_img(t_fdf *params, int x, int y, int colors)
{
	unsigned char 	r;
	unsigned char 	g;
	unsigned char 	b;
	unsigned int	color;
	int				zero;

	x += params->mov_x;
	y += params->mov_y;
	if (x >= 400 || x <= -400 || y <= -300 || y >= 300)
		return ;
	zero = 4 * 800 * 600 / 2 + 400 * 4;
	ft_printf("result = %i\n", zero + 4 * 800 * (int)y + (int)x * 4);
	color = mlx_get_color_value(params->mlx_ptr, colors);
	r = (color & 0XFF0000) >> 16;
	g = (color & 0XFF00) >> 8;
	b = (color & 0XFF);
	params->img_s[zero + 4 * 800 * y + x * 4] = r;
	params->img_s[zero + 4 * 800 * y + x * 4 + 1] = g;
	params->img_s[zero + 4 * 800 * y + x * 4 + 2] = b;
}

void	bresenham(t_fdf *params, int x1, int y1, int x2, int y2)
{
	float 	dx;
	float 	dy;
	float	p;
	int	i;
	int	y;
	int end;
	int	x;

	dx = abs(x1 - x2);
	dy = abs(y1 - y2);
	p = 2 * dy - dx;
	if (x1 > x2)
	{
		x = x2;
		y = y2;
		end = x1;
	}
	else
	{
		x = x1;
		y = y1;
		end = x2;
	}
	put_pxl_to_img(params, x, y, 0xFFFFFA);
	while (x < end)
	{
		x += 1;
		if	(p < 0)
		{
			p += 2 * dy;
		}
		else
		{
			y += 1;
			p += 2 * (dy - dx);
		}
		put_pxl_to_img(params, x, y, 0xFFFFFA);
	}
}
void	ft_bresenham(t_fdf *params, int x2, int y2, int x1, int y1)
{
	int		tabx[2];
	int		taby[2];
	int		e[2];
	int		x0;
	int		y0;
	
	x0 = x2;
	y0 = y2;
	tabx[0] = abs(x1 - x0);
	tabx[1] = x0 < x1 ? 1 : -1;
	taby[0] = abs(y1 - y0);
	taby[1] = y0 < y1 ? 1 : -1;
	e[0] = (tabx[0] > taby[0] ? tabx[0] : -taby[0]) / 2;
	while (x0 != x1 || y0 != y1)
	{
		put_pxl_to_img(params, x0, y0, 0xFFFFFA);
		e[1] = e[0];
		e[1] > -tabx[0] ? e[0] -= taby[0] : 1 == 1;
		e[1] > -tabx[0] ? x0 += tabx[1] : 1 == 1;
		e[1] < taby[0] ? e[0] += tabx[0] : 1 == 1;
		e[1] < taby[0] ? y0 += taby[1] : 1 == 1;
	}
}
void	calcul(t_fdf *params)
{
	int	i;
	int	j;
	float	x;
	float	y;


	create_img(params);
	i = 0;
	while (i < params->line)
	{
		j = 0;
		while (j < params->col)
		{
			x =  - ((sqrt(2.0) / 2) * (i - j) * params->z);
			y =  - ((sqrt(2.0 / 3) * (params->tab[i][j] * params->d) - 1 / sqrt(6) * (i + j)) * params->z);
			if (i + 1 < params->line)
				ft_bresenham(params, (int)x, (int)y, (int)-(((sqrt(2.0) / 2) * ((i + 1) - j) * params->z)), (int)-(((sqrt(2.0 / 3) * (params->tab[i + 1][j] * params->d) - 1 / sqrt(6) * ((i + 1) + j)) * params->z)));
			if (j + 1 < params->col)
				ft_bresenham(params, (int)x, (int)y, (int)-(((sqrt(2.0) / 2) * (i - (j + 1)) * params->z)), (int)-(((sqrt(2.0 / 3) * (params->tab[i][j + 1] * params->d) - 1 / sqrt(6) * (i + (j + 1))) * params->z)));
			printf("x = %f y = %f\n", x, y);
		//	if (x < 300 && x > -300 && y > -200 && y > -200)
		//		put_pxl_to_img(params, (int)x, (int)y, 0xFFFFFF);
			j++;
		}
		i++;
	}
}
