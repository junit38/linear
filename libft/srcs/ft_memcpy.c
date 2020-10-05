/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmery <jmery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:50:55 by jmery             #+#    #+#             */
/*   Updated: 2013/12/13 23:41:29 by jmery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*p1;
	char			*p2;

	i = 0;
	p1 = s1;
	p2 = (char*)s2;
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (s1);
}