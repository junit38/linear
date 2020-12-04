/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/11/14 15:18:24 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linear_regression.h"

static double	get_s1(char *line, t_data *data)
{
	char		**table;
	double		s1;

	s1 = 0;
	table = ft_strsplit(line, ',');
	if (table)
	{
		if (table[0] && table[1])
			s1 = get_estimated_price(ft_atoi(table[0]), data)
			- ft_atoi(table[1]);
		free_table(table);
	}
	return (s1);
}

static double	get_s2(char *line, t_data *data)
{
	char	**table;
	double	s2;

	s2 = 0;
	table = ft_strsplit(line, ',');
	if (table)
	{
		if (table[0] && table[1])
			s2 = (get_normalize_val(get_estimated_price(
				ft_atoi(table[0]), data), data)
				- get_normalize_val(ft_atoi(table[1]), data))
				* get_normalize_val(ft_atoi(table[0]), data);
		free_table(table);
	}
	return (s2);
}

static void		training(int fd, t_data *data)
{
	int		m;
	double	s1;
	double	s2;
	char	*line;

	m = 1;
	s1 = 0;
	s2 = 0;
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_isdigit(line[0]))
		{
			s1 += get_s1(line, data);
			s2 += get_s2(line, data);
			m++;
		}
		free(line);
	}
	data->s1 = s1 / m;
	data->s2 = s2 / m;
}

void			training_on_set(int fd, t_data *data)
{
	double	mins1;
	double	mins2;
	int		stop;
	int		iteration;

	stop = 0;
	mins2 = 0;
	mins1 = 0;
	iteration = 0;
	while (stop == 0 && iteration < 1000)
	{
		lseek(fd, 0, SEEK_SET);
		training(fd, data);
		if (abs_rounded(data->s2) - mins2 == 0 && data->s2 != 0
			&& (abs_rounded(data->s1) - mins1) == 0 && data->s1 != 0)
			stop = 1;
		else
		{
			mins2 = abs_rounded(data->s2);
			mins1 = abs_rounded(data->s1);
			data->theta0 = data->theta0 - (1 * data->s1);
			data->theta1 = data->theta1 - (1 * data->s2);
		}
		iteration++;
	}
}
