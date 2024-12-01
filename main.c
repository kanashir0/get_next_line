/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:20:45 by gyasuhir          #+#    #+#             */
/*   Updated: 2024/12/01 11:20:11 by gyasuhir         ###   ########.fr       */
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

    fd = open("my_text.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
        printf("line %d -> %s", i++, line);
    return (0);
}