/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/15 14:40:48 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linear_regression.h"

void		init_data(t_data *data)
{
	if (data)
	{
		data->theta0 = 0;
		data->theta1 = 0;
	}
}

double		get_theta(int fd)
{
	char	*line;
	double	theta;

	theta = 0;
	if (get_next_line(fd, &line) != 0)
	{
		theta = atof(line);
		free(line);
	}
	return (theta);
}

t_data		*load_data(char *filename)
{
	t_data		*data;
	int			fd;

	data = NULL;
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		data = (t_data*)malloc(sizeof(*data));
		if (data)
		{
			init_data(data);
			data->theta0 = get_theta(fd);
			data->theta1 = get_theta(fd);
		}
	}
	else
	{
		ft_putstr("File not found: ");
		ft_putendl(filename);
	}
	return (data);
}
