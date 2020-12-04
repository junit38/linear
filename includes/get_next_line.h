/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:39:46 by jmery             #+#    #+#             */
/*   Updated: 2020/12/04 14:49:30 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_save
{
	int				fd;
	char			*save;
	struct s_save	*next;
}				t_save;

int				get_next_line(int const fd, char **line);
char			*ft_strcpy(char *s1, char const *s2);
char			*ft_strncpy(char *s1, char const *s2, size_t n);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strchr(const char *s1, int c);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, char const *s2, size_t n);
size_t			ft_strlen(char const *s1);
void			ft_putnbr(int nb);
void			ft_putstr(char const *str);
char			*ft_cleanline(char const *s1);
int				ft_isend(char const *s1, size_t size);
size_t			ft_getend(char const *s1, size_t size);
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_bzero(void *s, size_t n);

#endif
