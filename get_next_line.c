/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:43:59 by agaga             #+#    #+#             */
/*   Updated: 2024/11/16 15:25:27 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

static char *read_from_fd(int fd, char *buf)
{
    int read_line = read(fd, buf, BUFFER_SIZE);
    if (read_line == -1)
        return NULL;
    buf[read_line] = '\0';
    return buf;
}

static char *join_buffers(char *s1, char *s2)
{
    char *joined = ft_strjoin(s1, s2);
    free(s1);
    return joined;
}

static char *read_file(int fd, char *buf, char *remainder)
{
    char *temp_buf;

    while ((temp_buf = read_from_fd(fd, buf)))
    {
        if (!remainder)
            remainder = ft_strdup("");
        remainder = join_buffers(remainder, temp_buf);
        if (ft_strchr(buf, '\n'))
            break;
    }
    return remainder;
}
/*
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
*/
static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
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
