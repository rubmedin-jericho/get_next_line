/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:24:32 by rubmedin          #+#    #+#             */
/*   Updated: 2025/03/24 15:24:34 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *free_str(char **buff_str)
{
	free((*buff_str));
	(*buff_str) = NULL;
	return (NULL);
}

char *get_next_line(int fd)
{
	static char	*buff_static = NULL;
	char		*buff_return;
	int			i;

	if(BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff_return = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buff_return)
		return (NULL);
	if(!buff_static)
		fill_str(&buff_return, fd);
	return (buff_return);
}

int	main()
{
	int	fd;
	char *str;
	
	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	while(str != NULL)
	{
		printf("Line: %s", str);
		str = get_next_line(fd);
	}
	return (0);
}
