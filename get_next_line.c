/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:14:07 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/12/01 11:09:19 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_list(t_list **lst)
{
	t_list	*last_node;
	t_list	*new_node;
	char	*new_content;
	int		i;
	int		j;

	i = 0;
	j = 0;
	last_node = get_last_node(*lst);
	new_content = (char *)malloc(BUFFER_SIZE + 1);
	new_node = (t_list *)malloc(sizeof(t_list));
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	while (last_node->content[i] && last_node->content[++i])
		new_content[j++] = last_node->content[i];
	new_content[j] = '\0';
	new_node->content = new_content;
	new_node->next = NULL;
	free_all(lst, new_node, new_content);
}

char	*get_line_from_list(t_list *lst)
{
	int		line_len;
	char	*line;

	if (lst == NULL)
		return (NULL);
	line_len = get_line_len(lst);
	line = (char *)malloc(line_len + 1);
	if (line == NULL)
		return (NULL);
	copy_line_to_buf(lst, line);
	return (line);
}

void	insert_to_list(t_list **lst, char *content)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node = get_last_node(*lst);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = content;
	new_node->next = NULL;
}

void	generate_list(t_list **lst, int fd)
{
	int		bytes_read;
	char	*buf;

	while (!found_newline(*lst))
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
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
