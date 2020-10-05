/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_regression.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 13:51:32 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINEAR_REGRESSION_H
# define FT_LINEAR_REGRESSION_H

# include "libft.h"
# include "ft_linear_regression_typedef.h"
# include "ft_linear_regression_structs.h"
# include "get_next_line.h"

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

/*
** DATA.C
*/
t_data	*load_data(char *filename);

/*
** MATHS.C
*/
double	abs_rounded(double a);

/*
** MODEL.C
*/
t_data	*create_new_model();
void	ft_write_model(char *argv, t_data *data);

/*
** NORMALIZE.C
*/
int		get_normalize_max(int fd);
int		get_normalize_min(int fd);
double	get_normalize_val(int val, t_data *data);

/*
** PRICE.C
*/
double	get_estimated_price(int km, t_data *data);

/*
** SET.C
*/
int		get_max_set(int fd);
int		get_min_set(int fd);
int		get_asc_set(int fd);
int		get_desc_set(int fd);

/*
** TRAINING.C
*/
void	training_on_set(int fd, t_data *data);

/*
** TOOLS.C
*/
void	free_table(char **table);

#endif
