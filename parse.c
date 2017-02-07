/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:50:27 by agiulian          #+#    #+#             */
/*   Updated: 2017/02/07 19:48:17 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_parsemap(int fd, t_fdf params)
{
	char	*line;
	int		i;
	char	**tab_s;

	while (get_next_line(fd, &line))
	{
		i = 0;
		tab_s = ft_strsplit(line, ' ');
		if (!params->tab)
		{
			i = -1;
			params->width = ft_tablen(tab_s);
			tab = (int**)malloc(sizeof(int*) * params->width);
			while (++i < width)
				tab[i] = (int*)malloc(sizeof(int) * params->width);
			i = 0;
		}
		while (tab_s[i])
		{
			tab[i] = ft_atoi(tab_s[i]);
			
		}
		if (i != width)
			return (
	}
}
