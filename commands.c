/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:29:01 by agiulian          #+#    #+#             */
/*   Updated: 2017/04/01 19:10:04 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int keycode, t_fdf *params)
{
	if (keycode == 12)
		params->z *= 2;
	else if (keycode == 13 && params->z / 2 >= 1)
		params->z /= 2;
	else if (keycode == 14)
		params->d *= 2;
	else if (keycode == 17 && params->d / 2 >= 1)
		params->d /= 2;
	calcul(params);
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, \
			params->img_ptr, 0, 0);
}

void	ft_movement(int keycode, t_fdf *params)
{
	if (keycode == 123)
		params->mov_x -= 10;
	else if (keycode == 126)
		params->mov_y -= 10;
	else if (keycode == 124)
		params->mov_x += 10;
	else if (keycode == 125)
		params->mov_y += 10;
	calcul(params);
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, \
			params->img_ptr, 0, 0);
}

void	ft_reset(t_fdf *params)
{
	init_params(params);
	calcul(params);
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, \
			params->img_ptr, 0, 0);
}

void	ft_changecolor(t_fdf *params)
{
	if (params->color == 0xFFFFFF)
		params->color = 0xFF0000;
	else if (params->color == 0xFF0000)
		params->color = 0x0000FF;
	else if (params->color == 0x0000FF)
		params->color = 0x00FF00;
	else if (params->color == 0x00FF00)
		params->color = 0xFFFF00;
	else if (params->color == 0xFFFF00)
		params->color = 0xFF00FF;
	else if (params->color == 0xFF00FF)
		params->color = 0x00FFFF;
	else if (params->color == 0x00FFFF)
		params->color = 0xFFFFFF;
	calcul(params);
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, \
			params->img_ptr, 0, 0);
}

int		ft_commands(int keycode, t_fdf *params)
{
	void	*fix;

	fix = params->mlx_ptr;
	if (keycode == 53)
	{
		free_params(params);
		exit(0);
	}
	else if (keycode == 12 || keycode == 13 || keycode == 14 || keycode == 17)
		ft_zoom(keycode, params);
	else if (keycode == 123 || keycode == 124 || keycode == 125 || \
		keycode == 126)
		ft_movement(keycode, params);
	else if (keycode == 15)
		ft_reset(params);
	else if (keycode == 8)
		ft_changecolor(params);
	return (0);
}
