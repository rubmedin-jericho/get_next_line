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

char *get_next_line(int fd)
{
	static char	*buff_static = NULL;
	char		*buff_tmp;
	char		*buff_return;
	int			count_read;


	if(BUFFER_SIZE < 0 || read(fd, NULL, 0))
		return (NULL);	
	if(buff_static != NULL)
		buff_static_cpy(&buff_static, &buff_return);	
	else
	{
		if(fill_buff_tmp(fd, &buff_tmp, &count_read))
			return (NULL);
		if(cpy_str(&buff_static, buff_tmp, &buff_return))
			return (NULL);
		if(count_read == 0)
			return (NULL);
	}
	return (buff_return);
}

#include <stdio.h>

int	main()
{
	int	fd;
	char *str;
	
	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	while(str != NULL)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
	return (0);
}
