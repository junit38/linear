/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 13:46:32 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linear_regression.h"

static double	get_current(char *line)
{
	char	**table;
	double	current;

	table = ft_strsplit(line, ',');
	current = ft_atoi(table[0]);
	free_table(table);
	return (current);
}

int				get_normalize_max(int fd)
{
	int		max;
	int		current;
	int		isfirst;
	char	*line;

	max = 0;
	isfirst = 1;
	lseek(fd, 0, SEEK_SET);
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_isdigit(line[0]))
		{
			current = get_current(line);
			if (isfirst)
			{
				max = current;
				isfirst = 0;
			}
			if (current > max)
				max = current;
		}
		free(line);
	}
	return (max);
}

int				get_normalize_min(int fd)
{
	int		min;
	int		current;
	int		isfirst;
	char	*line;

	min = 0;
	isfirst = 1;
	lseek(fd, 0, SEEK_SET);
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_isdigit(line[0]))
		{
			current = get_current(line);
			if (isfirst)
			{
				min = current;
				isfirst = 0;
			}
			if (current < min)
				min = current;
		}
		free(line);
	}
	return (min);
}


double			get_normalize_val(int val, t_data *data)
{
	double		normalize_val;

	normalize_val = (double)(val - data->xmin) / (data->xmax - data->xmin);
	return (normalize_val);
}
