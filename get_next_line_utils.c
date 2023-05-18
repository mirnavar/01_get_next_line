/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:30:49 by mirnavar          #+#    #+#             */
/*   Updated: 2023/05/18 11:13:42 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char *str);
char	*ft_strjoin(char *s, char *s2);

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
//	if ((unsigned char)c == 0)
//		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s)
	{
		s = (char *)malloc((sizeof(char) * 1));
		s[0] = '\0';
	}
	if (!s || !s2)
		return (NULL);
	s3 = malloc((sizeof(char)) * ((ft_strlen(s) + ft_strlen(s2)) + 1));
	if (!s3) //confirmar que es igual a s3 == NULL
		return (NULL);
	while (s[i++] != '\0')
		s3[i] = s[i];
	while (s2[j] != '\0')
		s3[i++] = s2[j++];
	s3[ft_strlen(s) + ft_strlen(s2)] = '\0';
	free(s);
	return (s3);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
