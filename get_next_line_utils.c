/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:44:06 by agaga             #+#    #+#             */
/*   Updated: 2024/11/16 15:36:50 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_list	ft_lstadd(t_list *buff_list, char *buffer)
{
	t_list	*tmp;

	if (buffer == NULL || buff_list == NULL)
		return (NULL);
	if (!buff_list)
		buff_list = buffer;
	else
	{
		tmp = ft_lstlast(buff_list);
		tmp->next = buffer;
	}
}


char	*ft_strchr(const char *str, int c)
{
	if (str == NULL)
		return (NULL);
	while (*str)
	{
		if (str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*extract_line(t_list **buff_list)
{
	
}
