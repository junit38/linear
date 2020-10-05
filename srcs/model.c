/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 14:20:20 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linear_regression.h"

t_data		*create_new_model(void)
{
	t_data		*data;
	int			fd;

	data = (t_data*)malloc(sizeof(*data));
	if (data)
	{
		fd = open("model", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd != -1)
			write(fd, "0\n0", 3);
		data->theta0 = 0;
		data->theta1 = 0;
		data->s1 = 0;
		data->s2 = 0;
		data->asc = 1;
	}
	return (data);
}

void		ft_write_model(char *argv, t_data *data)
{
	int			fd;

	if (argv == NULL)
		argv = "model";
	fd = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd != -1)
	{
		if (data)
			dprintf(fd, "%f\n%f", data->theta0, data->theta1);
		close(fd);
	}
}
