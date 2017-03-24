/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:04:27 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/24 01:07:02 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_img(t_fdf *params)
{
	int bits_per_pixel;
	int size_line;
	int endian;

	params->img_ptr = mlx_new_image(params->mlx_ptr, 800,6000);
	params->img_s = mlx_get_data_addr(params->img_ptr, &bits_per_pixel, &size_line, &endian);

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
			x = (sqrt(2)/2) * (j - i) * 10;
			y = sqrt(2/3) * params->tab[i][j] + 1 / sqrt(6) * (i + j) * 10;
			params->img_s[4 * 800 * (int)y + (int)x * 4] = 255;
			printf("x = %i\n", (int)x);
			printf("y = %f\n", y);
			j++;
		}
		i++;
	}
}
