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

#include "libft.h"

char	*get_next_line(int fd)
{
	char	*buf;
	size_t	byte_r;
	size_t	bytes_read;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	while (1)
	{
		byte_r = read(fd, buf, 1);
		if (byte_r == 0 || bytes_read > BUFFER_SIZE - 1)
			break;
		if (byte_r < 0)
			return (NULL);
		bytes_read += byte_r;
	}
	buf[bytes_read] = '\0';
	return (buf);
}
