/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   training.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 14:31:12 by mery             ###   ########.fr       */
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
			s1 = get_estimated_price(ft_atoi(table[0]), data) - ft_atoi(table[1]);
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
			s2 = (get_estimated_price(ft_atoi(table[0]), data)
			- ft_atoi(table[1])) * get_normalize_val(ft_atoi(table[0]), data);
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
		if (ft_strcmp(line, "km,price") != 0)
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

static int		training_on_set_2(int fd, t_data *data)
{
	double	mins2;
	int		stop2;
	int		iteration;

	stop2 = 0;
	mins2 = 0;
	iteration = 0;
	while (stop2 == 0)
	{
		lseek(fd, 0, SEEK_SET);
		training(fd, data);
		if (abs_rounded(data->s2) == mins2 && data->s2 != 0
			&& data->theta1 != 0)
			stop2 = 1;
		else
		{
			mins2 = abs_rounded(data->s2);
			data->theta1 = data->theta1 - (0.00001 * data->s2);
		}
		iteration++;
	}
	return (iteration);
}

void			training_on_set(int fd, t_data *data)
{
	double	mins1;
	int		stop1;
	int		iteration;

	mins1 = 0;
	stop1 = 0;
	iteration = 0;
	while (stop1 == 0 && iteration < 8000)
	{
		data->theta1 = 0;
		iteration += training_on_set_2(fd, data);
		if (abs_rounded(data->s1) == mins1 && data->s1 != 0)
			stop1 = 1;
		else
		{
			mins1 = abs_rounded(data->s1);
			data->theta0 = data->theta0 - (0.00001 * data->s1);
		}
		iteration++;
	}
}
