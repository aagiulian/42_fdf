/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:50:27 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/22 18:34:57 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_parsemap(int fd, t_fdf *params)
{
	char	*line;
	int		i;
	int		j;
	char	**tab_s;

	i = 0;
	params->tab = NULL;
	while (get_next_line(fd, &line))
	{
		j = 0;
		tab_s = ft_strsplit(line, ' ');
		if (!params->tab)
		{
			i = -1;
			params->width = ft_tablen(tab_s);
			params->tab = (int**)malloc(sizeof(int*) * params->width);
			while (++i < params->width)
				params->tab[i] = (int*)malloc(sizeof(int) * params->width);
			i = 0;
		}
		while (tab_s[j])
		{
			params->tab[i][j] = ft_atoi(tab_s[j]);
			ft_printf("%i ", params->tab[i][j]);
			j++;
		}
		ft_tabdel(&tab_s);
		if (j != params->width)
			return (0);
		ft_printf("\n");
		i++;
	}
	return (1);
}
