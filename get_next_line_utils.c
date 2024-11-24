/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:17:24 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/11/24 13:53:02 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *lst)
{
	t_list	*last_node;
	size_t	i;

	last_node = get_last_node(lst);
	i = 0;
	while (last_node->content[i] && i < BUFFER_SIZE)
	{
		if (last_node->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*get_last_node(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	get_line_len(t_list *lst);

void	copy_line_to_buf(t_list *lst, char *buf);