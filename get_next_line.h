/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:44:03 by agaga             #+#    #+#             */
/*   Updated: 2024/11/16 15:35:00 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
t_list	ft_lstadd(t_list *buff_list, char *buffer);
char	*ft_strchr(const char *str, int c);
char	*extract_line(t_list **buff_list);

#endif