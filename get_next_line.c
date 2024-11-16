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

char *get_next_line(int fd)
{
	static t_list	*buff_list = NULL;
	char			*line;
	char			buffer[BUFFER_SIZE + 1];
	int				byt_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	byt_read = read(fd, buffer, BUFFER_SIZE);
	while (byt_read > 0)
	{
		buffer[byt_read] = '\0';
		buff_list = ft_lstadd(buff_list, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (byt_read < 0)
		return (NULL);
	line = extract_line(&buff_list);
	return (line);
}


