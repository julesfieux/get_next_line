/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:44:24 by jfieux            #+#    #+#             */
/*   Updated: 2021/01/28 17:57:20 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_new_line(char *str)
{
	int		i;
	char	*res;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_new_save(char *str)
{
	int		i;
	int		j;
	char	*res;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	if (!(res = malloc(sizeof(char) * ((ft_strlen(str) - i) + 1))))
		return (0);
	i++;
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*save[1024];

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!save[fd])
	{
		if ((save[fd] = malloc(sizeof(char) * 1)) == NULL)
			return (-1);
		save[fd][0] = '\0';
	}
	while (ft_found_return(save[fd]) == 0 && ret != 0)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(save[fd]);
			return (-1);
		}
		buf[ret] = '\0';
		save[fd] = ft_strjoin(save[fd], buf);
	}
	*line = ft_new_line(save[fd]);
	save[fd] = ft_new_save(save[fd]);
	if (ret == 0)
		return (0);
	return (1);
}
