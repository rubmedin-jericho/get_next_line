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

void	fill_buff(char *buff_tmp, t_node line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while(line.str[i])
	{
		if(line.str[i - 1] == '\n')
		{
			j = 0;
			while(line.str[i])
				buff_tmp[j++] = line.str[i++];
		}
		else
			i++;
	}
}

int		read_fd(t_node *line, int fd)
{
	line->str = malloc(sizeof(char *) * BUFFER_SIZE + 1);	
	if(!line->str)
		return (1);
	if(read(fd, line->str, BUFFER_SIZE) <= 0)
		return (1);
	return (0);
}

#include <stdio.h>
char *get_next_line(int fd)
{
	//static char *buff_tmp = NULL;
	t_node		line;		

	if(!fd || BUFFER_SIZE <= 0 || read_fd(&line, fd))
		return (NULL);
	//fill_buff(buff_tmp, line);
	printf("\nresult: %s\n", line.str);
	return (line.str);
}

//#include <stdio.h>
int	main(int argc, char **argv)
{
	int	fd;
	char content[100];
	char rm[100];
	char *name_file = "test";
	char *str;

	if(argc > 2)
	{
		printf("ERROR_PARAMETERS");
		return (1);
	}
	fd = open(name_file, O_RDONLY|O_CREAT);
	if(argc == 1)
		sprintf(content, "echo Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum. > %s", name_file);
	else
		sprintf(content, "echo %s > %s", argv[1], name_file);
	system(content);
	str = get_next_line(fd);
	while(str != NULL)
	{
		str = get_next_line(fd);
		//printf("%s", str);
	}
	sprintf(rm, "rm -rf %s", name_file);
	system(rm);
	return (0);
}
