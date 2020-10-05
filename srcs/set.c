/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 13:46:20 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linear_regression.h"

static double	get_current(char *line)
{
	char	**table;
	double	current;

	table = ft_strsplit(line, ',');
	current = ft_atoi(table[1]);
	free_table(table);
	return (current);
}

int				get_max_set(int fd)
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

int				get_min_set(int fd)
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

int				get_asc_set(int fd)
{
	int		asc;
	int		current;
	int		prev;
	int		isfirst;
	char	*line;

	asc = 0;
	isfirst = 1;
	lseek(fd, 0, SEEK_SET);
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_isdigit(line[0]))
		{
			current = get_current(line);
			if (isfirst)
				isfirst = 0;
			else if (prev < current)
				asc++;
			prev = current;
		}
		free(line);
	}
	return (asc);
}

int				get_desc_set(int fd)
{
	int		desc;
	int		current;
	int		prev;
	int		isfirst;
	char	*line;

	desc = 0;
	isfirst = 1;
	lseek(fd, 0, SEEK_SET);
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_isdigit(line[0]))
		{
			current = get_current(line);
			if (isfirst)
				isfirst = 0;
			else if (prev > current)
				desc++;
			prev = current;
		}
		free(line);
	}
	return (desc);
}
