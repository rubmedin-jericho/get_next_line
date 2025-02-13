/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:53:59 by rubmedin          #+#    #+#             */
/*   Updated: 2025/02/13 16:54:01 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char *get_next_line(int fd)
{

}

int	main(void)
{
	int	fd;
	char *str;

	str = get_next_line(fd);
	while(str != NULL)
	{
		fd = open("test.txt", O_RDONLY|O_CREAT);
		str = get_next_line(fd);
		printf("%s", str);
	}
	return (0);
}
