/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prescision.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 13:44:18 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linear_regression.h"

static double	get_diff(char *line, t_data *data)
{
	char		**table;
	double		diff;

	diff = 0;
	table = ft_strsplit(line, ',');
	if (table && table[0] && table[1])
	{
		diff = fabs(get_estimated_price(ft_atoi(table[0]), data)
		- ft_atoi(table[1]));
		diff = diff / get_estimated_price(ft_atoi(table[0]), data) * 100;
	}
	free_table(table);
	return (diff);
}

static void		prescision_on_set(int fd, t_data *data)
{
	int		m;
	double	diff;
	char	*line;

	m = 1;
	diff = 0;
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_isdigit(line[0]))
		{
			diff += get_diff(line, data);
			m++;
		}
		free(line);
	}
	printf("Prescision = %f\n", fabs(diff / m));
}

void			train_model(char *file_data, t_data *data)
{
	int		fd;

	if (data)
	{
		fd = open(file_data, O_RDONLY);
		if (fd != -1)
		{
			prescision_on_set(fd, data);
			close(fd);
		}
		else
		{
			ft_putstr("File not found: ");
			ft_putendl(file_data);
		}
	}
}

int				main(int argc, char **argv)
{
	t_data		*data;

	data = NULL;
	if (argc == 2)
	{
		data = load_data("model");
		train_model(argv[1], data);
	}
	else if (argc > 2)
	{
		data = load_data(argv[2]);
		train_model(argv[1], data);
	}
	else
		ft_putstr("Usage: ft_prescision data [model]\n");
	free(data);
	return (0);
}
