/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:20:19 by agiulian          #+#    #+#             */
/*   Updated: 2017/04/01 18:16:16 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_params(t_fdf *params)
{
	params->mov_x = 0;
	params->mov_y = 0;
	params->z = 20;
	params->d = 1;
	params->color = 0xFFFFFF;
}
