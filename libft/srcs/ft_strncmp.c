/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:27:03 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:32:18 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && res == 0 && i < n)
	{
		if (s1[i] != s2[i])
			res = s1[i] - s2[i];
		i++;
	}
	if (res == 0 && i < n)
		res = s1[i] - s2[i];
	return (res);
}
