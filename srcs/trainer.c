/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trainer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 13:57:17 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linear_regression.h"

void		get_abscisse(int fd, t_data *data)
{
	int		asc;
	int		desc;

	asc = get_asc_set(fd);
	desc = get_desc_set(fd);
	if (asc > desc)
	{
		data->asc = -1;
		data->theta0 = get_max_set(fd);
	}
	else
		data->theta0 = get_min_set(fd);
}

void		train_model(char *file_data, t_data *data)
{
	int		fd;

	if (data)
	{
		fd = open(file_data, O_RDONLY);
		if (fd != -1)
		{
			get_abscisse(fd, data);
			data->xmax = get_normalize_max(fd);
			data->xmin = get_normalize_min(fd);
			training_on_set(fd, data);
			close(fd);
		}
		else
		{
			ft_putstr("File not found: ");
			ft_putendl(file_data);
		}
	}
}

int			main(int argc, char **argv)
{
	t_data		*data;

	data = NULL;
	if (argc == 2)
	{
		data = create_new_model();
		train_model(argv[1], data);
		ft_write_model(NULL, data);
	}
	else if (argc > 2)
	{
		data = create_new_model();
		train_model(argv[1], data);
		ft_write_model(argv[2], data);
	}
	else
		ft_putstr("Usage: ft_trainer data [model]\n");
	free(data);
	while (1) {};
	return (0);
}
