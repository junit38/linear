/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trainer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 14:29:59 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linear_regression.h"

int				check_file(int fd)
{
	int		is_formated;
	char	*line;
	char	**table;

	is_formated = 1;
	lseek(fd, 0, SEEK_SET);
	while (get_next_line(fd, &line) != 0 && is_formated == 1)
	{
		if (ft_isdigit(line[0]))
		{
			table = ft_strsplit(line, ',');
			if (table)
			{
				if (!table[0] || !table[1])
					is_formated = 0;
				free_table(table);
			}
		}
		free(line);
	}
	return (is_formated);
}

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
			if (check_file(fd))
				training_on_set(fd, data);
			else
				ft_putstr("File badly formated\n");
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
		if (data)
			free(data);
	}
	else if (argc > 2)
	{
		data = create_new_model();
		train_model(argv[1], data);
		ft_write_model(argv[2], data);
		if (data)
			free(data);
	}
	else
		ft_putstr("Usage: ft_trainer data [model]\n");
	return (0);
}
