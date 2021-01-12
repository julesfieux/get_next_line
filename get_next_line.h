/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:42:16 by jfieux            #+#    #+#             */
/*   Updated: 2021/01/12 14:42:46 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

int BUFFER_SIZE;
int get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_found_return(char *str);
int		ft_strlen(const char *str);

#endif
