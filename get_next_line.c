/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:14:07 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/11/02 17:00:15 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_list(t_list **lst)
{
	return ;
}

char	*get_line_from_list(t_list *lst)
{
	return (&"");
}

void	insert_to_list(t_list **lst, char *content)
{
	return ;
}

void	generate_list(t_list **lst, int fd)
{
	int		bytes_read;
	char	*buf;

	while (!found_newline(*lst))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		// TODO: Check for read returning error (-1)
		if (!bytes_read)
		{
			free(buf);
			return ;
		}
		buf[bytes_read] = '\0';
		insert_to_list(lst, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	generate_list(&lst, fd);
	if (lst == NULL)
		return (NULL);
	line = get_line_from_list(lst);
	clear_list(&lst);
	return (line);
}
