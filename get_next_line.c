/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:43:59 by agaga             #+#    #+#             */
/*   Updated: 2024/11/18 13:57:35 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

static char	*read_file(int fd, char *buf, char *leftover)
{
	int		read_line;
	char	*tmp_buffer;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!leftover)
			leftover = ft_strdup("");
		tmp_buffer = leftover;
		leftover = ft_strjoin(tmp_buffer, buf);
		free(tmp_buffer);
		tmp_buffer = NULL;
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (leftover);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*leftover;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
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
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = read_file(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
