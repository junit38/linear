/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mery <mery@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 12:36:35 by jmery             #+#    #+#             */
/*   Updated: 2020/09/01 12:33:18 by mery             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cat_and_realoc(char *tmp, char buf[], int ret)
{
	char	*tmp2;

	tmp2 = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + ret + 1));
	if (tmp2)
	{
		ft_strncpy(tmp2, tmp, ft_strlen(tmp));
		ft_strncat(tmp2, buf, ret);
	}
	free(tmp);
	return (tmp2);
}

t_save	*ft_save_next_line(char buf[], int *ret, int fd, t_save *save)
{
	int		newline_i;
	t_save	*save2;

	newline_i = 0;
	while (buf[newline_i] != '\n' && newline_i < *ret)
		newline_i++;
	if (buf[newline_i] != '\n')
	{
		if (save && save->save)
		{
			free(save->save);
			free(save);
		}
		return (NULL);
	}
	if (save && save->fd == fd)
	{
		free(save->save);
		save->save = (char*)malloc(sizeof(char) * (*ret - newline_i + 1));
		if (save->save)
			ft_strncpy(save->save, buf + newline_i + 1, *ret - newline_i - 1);
		return (save);
	}
	save2 = (t_save*)malloc(sizeof(t_save));
	if (save2)
	{
		save2->fd = fd;
		save2->next = save;
		save2->save = (char*)malloc(sizeof(char) * (*ret - newline_i + 1));
		if (save2->save)
			ft_strncpy(save2->save, buf + newline_i + 1, *ret - newline_i - 1);
	}
	return (save2);
}

char	*ft_load_next_line(int fd, char buf[], int *ret)
{
	char	*tmp;
	char	*tmp2;
	int		newline_index;

	tmp = (char*)malloc(sizeof(char) * (*ret + 1));
	if (tmp)
		ft_strncpy(tmp, buf, *ret);
	while (!ft_strchr(tmp, '\n') && *ret > 0)
	{
		*ret = read(fd, buf, BUFF_SIZE);
		tmp2 = (char*)malloc(sizeof(char) * (ft_strlen(tmp) + *ret + 1));
		if (tmp2)
		{
			ft_strncpy(tmp2, tmp, ft_strlen(tmp));
			ft_strncat(tmp2, buf, *ret);
		}
		free(tmp);
		tmp = tmp2;
	}
	newline_index = 0;
	while (tmp[newline_index] != '\n' && tmp[newline_index])
		newline_index++;
	tmp2 = (char*)malloc(sizeof(char) * (newline_index + 1));
	if (tmp2)
		ft_strncpy(tmp2, tmp, newline_index);
	free(tmp);
	return (tmp2);
}

t_save	*ft_get_save(t_save *save, int fd)
{
	t_save	*current;
	t_save	*last;

	if (save == NULL)
		return (save);
	current = save;
	if (current->next == NULL)
		return (current);
	while (current != NULL && current->fd != fd)
	{
		last = current;
		current = current->next;
	}
	if (current && current->fd == fd && current != save)
	{
		last->next = current->next;
		if (current->save && current->save[0] != '\0')
		{
			current->next = save;
			save = current;
		}
		else
		{
			free(current->save);
			free(current);
		}
	}
	return (save);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE];
	static t_save	*save;

	save = ft_get_save(save, fd);
	if (save && save->save && save->save[0] != '\0' && save->fd == fd)
	{
		ft_strcpy(buf, save->save);
		ret = ft_strlen(save->save) + 1;
		*line = ft_load_next_line(fd, buf, &ret);
		save = ft_save_next_line(buf, &ret, fd, save);
		return (1);
	}
	else
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret <= 0)
			return (ret);
		*line = ft_load_next_line(fd, buf, &ret);
		save = ft_save_next_line(buf, &ret, fd, save);
		return (1);
	}
	return (-1);
}
