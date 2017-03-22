/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:22:29 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/22 17:30:14 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_fdf	*params;
	int		fd;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename>");
		return (EXIT_FAILURE);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_printf("file error\n");
		return (EXIT_FAILURE);
	}
	if (!(params = (t_fdf*)malloc(sizeof(t_fdf))))
		return (EXIT_FAILURE);
	if (!ft_parsemap(fd, params))
	{
		ft_printf("map error");
		return (EXIT_FAILURE);
	}
	if ((params->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((params->win_ptr = mlx_new_window(params->mlx_ptr, 1000, 1000, "fdf")) == NULL)
		return (EXIT_FAILURE);
	mlx_key_hook(params->win_ptr, ft_commands, params);
	mlx_loop(params->win_ptr);
	return (EXIT_SUCCESS);
}
