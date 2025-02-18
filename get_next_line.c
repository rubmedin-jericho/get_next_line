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

/*char *get_next_line(int fd)
{

}
*/

#include <stdio.h>
int	main(int argc, char **argv)
{
	int	fd;
	char content[100];
	char *name_file = "test";
	//char *str;

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
		printf("%s", str);
	}
	system("rm -rf test");
	return (0);
}
