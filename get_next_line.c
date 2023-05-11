/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:50:48 by mirnavar          #+#    #+#             */
/*   Updated: 2023/05/11 17:09:29 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_new_str(str);
	return (line);
}

char	*ft_read_str(int fd, char *str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buff)
        return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		printf("%d", rd_bytes);
		if (rd_bytes == -1)
		{
			free(buff);
			free(str);
			return (0);
		}
		buff[rd_bytes] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (NULL);
	}
	free(buff);
	return (str);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*str2;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	str2 = (char *)malloc((i + 2) * sizeof(char));
	
}

int	main(int argc, char **argv)
{
	int	fd;
	fd = 0;
//	printf("%d", argc);
//	printf("%s", (argv[1]));
	if (argc > 1)
	{
		fd = open((argv[1]), O_RDONLY);
		printf("%d\n", fd);
		get_next_line(fd);
	}
	return (0);
}
