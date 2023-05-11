/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:52:40 by mirnavar          #+#    #+#             */
/*   Updated: 2023/05/11 16:16:29 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

// Library for READ
#include <unistd.h>

//Library for MALLOC
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *buff);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s, const char *s2);

#endif
