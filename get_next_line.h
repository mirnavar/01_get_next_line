/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:52:40 by mirnavar          #+#    #+#             */
/*   Updated: 2023/05/16 17:20:30 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Library for READ
# include <unistd.h>

//Library for MALLOC
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *buff);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s, char *s2);
size_t	ft_strlen(char *str);
char	*ft_get_line(char *str);
char	*ft_new_str(char *str);

#endif
