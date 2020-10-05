/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_regression_structs.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:46 by jmery             #+#    #+#             */
/*   Updated: 2020/10/05 12:35:22 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINEAR_REGRESSION_STRUCTS_H
# define FT_LINEAR_REGRESSION_STRUCTS_H

# include "ft_linear_regression_typedef.h"

typedef struct		s_data
{
	double			theta0;
	double			theta1;
	double			s1;
	double			s2;
	int				asc;
	char			*file;
	int				xmin;
	int				xmax;
}					t_data;

#endif
