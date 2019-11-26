/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:33:23 by mamaquig          #+#    #+#             */
/*   Updated: 2019/11/26 17:18:15 by mamaquig         ###   ########.fr       */
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
	int nb = 1;
	int fd;
	char *line = NULL;

	if (ac < 1)
		return (printf("Nom de fichier oublié.\n"));
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		free(line);
	free(line);
	get_next_line(fd, &line);
	free(line);
	while(1)
		nb++;
	return (0);
}
