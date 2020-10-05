/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 13:44:29 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linear_regression.h"

#include <stdio.h>

void		predict(t_data *data)
{
	char	buf[1028];
	int		ret;
	double	price;

	ret = 0;
	ft_putstr("Enter your car mileage:\n");
	while ((ret = read(1, buf, 1027)) != 0)
	{
		buf[ret] = '\0';
		price = get_estimated_price(ft_atoi(buf), data);
		printf("Estimated price is: %f\n", price);
		ft_putstr("Enter your car mileage:\n");
	}
}

int			main(int argc, char **argv)
{
	t_data		*data;

	if (argc == 2)
	{
		data = load_data(argv[1]);
		if (data)
		{
			printf("theta0: %f, theta1: %f\n", data->theta0, data->theta1);
			predict(data);
			free(data);
		}
	}
	else
		ft_putstr("Usage: ft_predict model\n");
	return (0);
}
