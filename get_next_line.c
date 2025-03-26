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

char *get_next_line(int fd)
{
	static char	*buff_static = NULL;
	char		*buff_tmp;
	char		*buff_return;
	int			count_read;

	if(!fd || fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);	
	if(fill_buff(fd, &buff_tmp, &count_read))
		return (NULL);
	
	//if(!buff_static)
	//	cut_str(&buff_static, buff, count_read);
	//else
	//{
	//	
	//}

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
		printf("str_1: %s", str);
		str = get_next_line(fd);
	}
	return (0);
}
