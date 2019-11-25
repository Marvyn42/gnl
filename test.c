/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:33:23 by mamaquig          #+#    #+#             */
/*   Updated: 2019/11/25 14:20:58 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	int fd;
//	char *tmp;
	char *line = NULL;

	if (ac != 2)
		return (printf("Nom de fichier oublié.\n"));
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
		get_next_line(fd, &line);
	return (0);
}
