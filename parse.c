/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:50:27 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/10 13:25:35 by agiulian         ###   ########.fr       */
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
			printf("%i ", params->tab[i][j]);
			j++;
		}
		if (j != params->width)
			return (0);
		printf("\n");
		i++;
	}
	return (1);
}
