/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:43:59 by agaga             #+#    #+#             */
/*   Updated: 2024/11/18 15:11:28 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

static char	*read_file(int fd, char *buf, char **leftover)
{
	int		read_line;
	char	*tmp_buffer;

	read_line = 1;
	while (read_line > 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!(*leftover))
			*leftover = ft_strdup("");
		tmp_buffer = *leftover;
		*leftover = ft_strjoin(tmp_buffer, buf);
		free(tmp_buffer);
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (*leftover);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*leftover;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (NULL);
	leftover = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*leftover == '\0')
	{
		free(leftover);
		leftover = NULL;
	}
	line[count + 1] = '\0';
	return (leftover);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_file(fd, buffer, &leftover);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftover = extract(line);
	return (line);
}
