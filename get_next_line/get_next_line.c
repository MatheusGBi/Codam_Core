/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/20 18:22:49 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/10/20 18:22:51 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*current_line(char *saved)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!saved || !saved[0])
		return (NULL);
	while (saved[i] != '\n' && saved[i] != 0)
		i++;
	if (saved[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = saved[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*left_over(char *saved)
{
	int		i;
	char	*left;
	int		j;

	i = 0;
	if (!saved || !saved[0])
		return (NULL);
	while (saved[i] != '\n' && saved[i] != 0)
		i++;
	if (saved[i] == '\n')
		i++;
	if (!saved[i])
		return (free(saved), NULL);
	left = malloc(sizeof(char) * (str_len(saved + i) + 1));
	if (!left)
		return (free(saved), NULL);
	j = 0;
	while (saved[i + j])
	{
		left[j] = saved[i + j];
		j++;
	}
	left[j] = '\0';
	return (free (saved), left);
}

char	*get_next_line(int fd)
{
	static char		*saved;
	char			*buffer;
	int				bytes;
	char			*line;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (bytes != 0 && !str_char(saved, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buffer), free(saved), saved = NULL, NULL);
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		line = buff_append(saved, buffer);
		saved = line;
	}
	line = current_line(saved);
	saved = left_over(saved);
	return (free(buffer), line);
}
/* 
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;
    int     line_count;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening test.txt");
        return (1);
    }

    line_count = 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", line_count, line);
    
        free(line);
        line_count++;
    }

    close(fd);
    return (0);
}
*/
