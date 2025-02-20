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

void	insert_node(t_node *current_node, t_node *new_node)
{
	t_node *node_tmp;

	node_tmp = current_node;
	if(!current_node)	
	{
		current_node = new_node;
		return ;
	}
	while(node_tmp->next != NULL)
		node_tmp = node_tmp->next;
	node_tmp->next = new_node;
}

t_node	*create_node(char *words)
{
	t_node *new_node;
	int		i;

	i = 0;
	new_node = malloc(sizeof(t_node));
	while(new_node->str[i])
	{
		new_node->str[i] = words[i];
		i++;
	}
	new_node->str[i] = '\0';
	new_node->next = NULL;
	return (new_node);
}

void	create_node_list(t_node **node, int fd)
{
	char	*buff_tmp;
	int		nbr_read;	
	t_node	*new_node;

	nbr_read = 1;
	while(nbr_read > 0)
	{			
		buff_tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);	
		nbr_read = read(fd, buff_tmp, BUFFER_SIZE);
		new_node = create_node(buff_tmp);	
		insert_node(*node, new_node);
	}
}

#include <stdio.h>
void print_node(t_node *node)
{
	t_node *node_tmp;

	node_tmp = node;
	while(node_tmp != NULL)
	{
		printf("str: %s\n", node_tmp->str);
		node_tmp = node_tmp->next;
	}
}

char *get_next_line(int fd)
{
	static t_node	*heap;

	if(!fd || fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	create_node_list(&heap, fd);
	print_node(heap);
	return (heap->str);
}

//#include <stdio.h>
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

//int	main(int argc, char **argv)
//{
//	int	fd;
//	char content[100];
//	char rm[100];
//	char *name_file = "test";
//	char *str;
//
//	if(argc > 2)
//	{
//		printf("ERROR_PARAMETERS");
//		return (1);
//	}
//	fd = open(name_file, O_RDONLY|O_CREAT);
//	if(argc == 1)
//		sprintf(content, "echo Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum. > %s", name_file);
//	else
//		sprintf(content, "echo %s > %s", argv[1], name_file);
//	system(content);
//	str = get_next_line(fd);
//	while(str != NULL)
//	{
//		printf("%s", str);
//		str = get_next_line(fd);
//	}
//	sprintf(rm, "rm -rf %s", name_file);
//	system(rm);
//	return (0);
//}
