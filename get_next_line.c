/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:50:48 by mirnavar          #+#    #+#             */
/*   Updated: 2023/05/12 12:17:18 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str=NULL;
	
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
		{	
			if (buff)
				free(buff);
			return (NULL);
		}
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
	if (!str2)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		{
			str2[i] = str[i];
			i++;	
		}
	str[i] = '\0';
//	free(str);
	return (str2);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		a;
	char	*new_str;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	i++;
	a = i;
	while (str[i] != '\0')
		i++;
	new_str = (char *)malloc((i - a + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = a;
	while (str[i] != '\0')// && str[i] != '\n')   //tambien != a '\n'? porque que pasa si el BUFFER_SIZE es grande y en mi buffer no hay un '\n' sino dos? es decir, que hay en total 3 trozos de lineas diferentes
		{
			new_str[i] = str[i];
			i++;
		}
	str[i] = '\0';
	free(str);
	return (new_str);
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
