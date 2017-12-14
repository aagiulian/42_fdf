/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:22:29 by agiulian          #+#    #+#             */
/*   Updated: 2017/04/01 19:10:32 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_params(t_fdf *params)
{
	int i;

	i = -1;
	while (++i < params->line)
		free(params->tab[i]);
	free(params->tab);
	free(params);
}

static int	ft_redcross(void)
{
	exit(0);
}

static int	start(t_fdf **params, char *file)
{
	if (!(*params = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
		return (-1);
	if (ft_parse_map(*params, file))
		return (-1);
	if (((*params)->mlx_ptr = mlx_init()) == NULL)
		return (-1);
	if (((*params)->win_ptr = mlx_new_window((*params)->mlx_ptr, \
					WIDTH, HEIGHT, "fdf")) == NULL)
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fdf	*params;

	params = NULL;
	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename>");
		return (EXIT_FAILURE);
	}
	if (start(&params, argv[1]))
		return (EXIT_FAILURE);
	init_params(params);
	calcul(params);
	if (!mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, \
				params->img_ptr, 0, 0))
		return (0);
	mlx_hook(params->win_ptr, 17, (1L << 17), ft_redcross, params);
	mlx_key_hook(params->win_ptr, ft_commands, params);
	mlx_loop(params->mlx_ptr);
	free_params(params);
	return (EXIT_SUCCESS);
}
