/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:01:15 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/12/01 11:11:19 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);

void	generate_list(t_list **lst, int fd);

void	insert_to_list(t_list **lst, char *content);

char	*get_line_from_list(t_list *lst);

void	clear_list(t_list **lst);

void	free_all(t_list **lst, t_list *new_lst, char *content);

void	copy_line_to_buf(t_list *lst, char *buf);

int		get_line_len(t_list *lst);

t_list	*get_last_node(t_list *lst);

int		found_newline(t_list *lst);

#endif
