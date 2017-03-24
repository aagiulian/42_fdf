/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:22:29 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/24 16:21:21 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_fdf	*params;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename>");
		return (EXIT_FAILURE);
	}
	if (!(params = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
		return (EXIT_FAILURE);
	if (ft_parse_map(params, argv[1]))
		return (EXIT_FAILURE);
	if ((params->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((params->win_ptr = mlx_new_window(params->mlx_ptr, 1000, 1000, "fdf")) == NULL)
		return (EXIT_FAILURE);
	calcul(params);
	if (!mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->img_ptr, 100, 100))
		return (0);
	ft_putstr("OL");
	//mlx_hook(params->win_ptr, 17, (1L<<17), ft_commands, params);
	mlx_key_hook(params->win_ptr, ft_commands, params);
	mlx_loop(params->mlx_ptr);
	return (EXIT_SUCCESS);
}
