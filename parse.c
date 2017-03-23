/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:50:27 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/23 20:19:55 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_parse_coord(int fd, t_fdf *params)
{
	char	*line;
	int		i;
	int		j;
	char	**tab_s;

	i = 0;
	params->tab = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		j = 0;
		tab_s = ft_strsplit(line, ' ');
		if (!params->tab)
		{
			i = -1;
			params->col = ft_tablen(tab_s);
			params->tab = (int**)malloc(sizeof(int*) * params->line);
			while (++i < params->col)
				params->tab[i] = (int*)malloc(sizeof(int) * params->col);
			i = 0;
		}
		while (tab_s[j])
		{
			params->tab[i][j] = ft_atoi(tab_s[j]);
			ft_printf("%i ", params->tab[i][j]);
			j++;
		}
		ft_tabdel(&tab_s);
		ft_strdel(&line);
		if (j != params->col)
			return (-1);
		ft_printf("\n");
		i++;
	}
	return (0);
}

int		ft_parse_map(t_fdf *params, char *file)
{
	int		fd;
	char	*line;
	int		ret;

	params->line = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_printf("file error\n");
		return (-1);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_strdel(&line);
		params->line++;
	}
	if (ret == -1)
	{
		ft_printf("file error\n");
		return (-1);
	}
	if (params->line == 0 || close(fd))
		return (-1);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	if (ft_parse_coord(fd, params) || close(fd))
	{
		ft_printf("map error\n");
		return (-1);
	}
	return (0);
}
