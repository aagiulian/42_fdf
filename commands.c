/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:29:01 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/23 15:55:06 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_commands(int keycode, t_fdf *params)
{
	void	*fix;

	fix = params->mlx_ptr;
	ft_printf("keycode = %i\n", keycode);
	if (keycode == 53 || keycode == 17)
		exit (0);
	else
		return (0);
}
