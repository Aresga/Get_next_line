/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:59:25 by agaga             #+#    #+#             */
/*   Updated: 2024/11/16 15:03:29 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int	fd;
	char *line;

	fd = open("testfile.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line = NULL)
			break;
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
