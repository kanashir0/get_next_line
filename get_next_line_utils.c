/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:17:24 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/12/01 11:24:40 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(t_list *lst)
{
	t_list	*last_node;
	size_t	i;

	last_node = get_last_node(lst);
	if (last_node == NULL)
		return (0);
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

int	get_line_len(t_list *lst)
{
	int	len;
	int	i;

	len = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			len++;
			if (lst->content[i] == '\n')
				return (len);
			i++;
		}
		lst = lst->next;
	}
	return (len);
}

void	copy_line_to_buf(t_list *lst, char *buf)
{
	int	i;
	int	j;

	i = 0;
	while (lst)
	{
		j = 0;
		while (lst->content[j])
		{
			buf[i] = lst->content[j];
			if (lst->content[j] == '\n')
			{
				buf[++i] = '\0';
				return ;
			}
			i++;
			j++;
		}
		lst = lst->next;
	}
	buf[i] = '\0';
}

void	free_all(t_list **lst, t_list *new_lst, char *content)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	if (new_lst->content[0])
		*lst = new_lst;
	else
	{
		free(content);
		free(new_lst);
	}
}
