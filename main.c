/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:20:45 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/12/01 13:02:21 by gyasuhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    char *line;
    int fd;
    int i = 1;
    int j = 0;

    fd = open("my_text.txt", O_RDONLY);
    while (j < 9)
    {
        line = get_next_line(fd);
        printf("line %d -> %s", i++, line);
        free(line);
        j++;
    }
    return (0);
}