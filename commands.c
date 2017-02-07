/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:29:01 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/07 18:39:05 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_commands(int keycode, t_fdf *params)
{
	void	*fix;

	fix = params->mlx_ptr;
	if (keycode == 53)
		exit (0);
	else
		return (0);
}
