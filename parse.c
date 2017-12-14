/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:50:27 by agiulian          #+#    #+#             */
/*   Updated: 2017/04/01 19:00:43 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_tab(t_fdf *params, char **tab_s)
{
	int i;

	i = -1;
	params->col = ft_tablen(tab_s);
	if (!(params->tab = (int**)malloc(sizeof(int*) * params->line)))
		exit(0);
	while (++i < params->line)
		params->tab[i] = (int*)malloc(sizeof(int) * params->col);
}

int			ft_parse_coord(int fd, t_fdf *params, char *line)
{
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
			init_tab(params, tab_s);
		while (tab_s[j])
		{
			params->tab[i][j] = ft_atoi(tab_s[j]);
			ft_strdel(&tab_s[j]);
			j++;
		}
		free(tab_s);
		ft_strdel(&line);
		if (j != params->col)
			return (-1);
		i++;
	}
	return (0);
}

int			ft_error(t_fdf *params, char *file)
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
	return (0);
}

int			ft_parse_map(t_fdf *params, char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	if (ft_error(params, file))
		return (-1);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	if (ft_parse_coord(fd, params, line) || close(fd))
	{
		ft_printf("map error\n");
		return (-1);
	}
	return (0);
}
