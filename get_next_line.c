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
	if(!new_node)
		return NULL;
	while(words[i])
	{
		new_node->str[i] = words[i];
		i++;
	}
	new_node->str[i] = '\0';
	new_node->next = NULL;
	return (new_node);
}

void	create_node_list(t_node **node, int fd, int *count)
{
	char	buff_tmp[BUFFER_SIZE + 1];
	int		nbr_read;	
	int		i = 0;
	t_node	*new_node;

	ft_bzero(buff_tmp, (size_t)BUFFER_SIZE);
	nbr_read = 1;
	while(nbr_read > 0)
	{			
		nbr_read = read(fd, buff_tmp, BUFFER_SIZE);
		buff_tmp[nbr_read] = '\0';
		new_node = create_node(buff_tmp);	
		insert_node(*node, new_node);
		*count += 1;
		i++;
	}
}

void print_node(t_node *node)
{
	t_node *node_tmp;
	int	i = 9;

	node_tmp = node;
	while(node_tmp != NULL && i > 0)
	{
		printf("str: %s\n", node_tmp->str);
		node_tmp = node_tmp->next;
		i--;
	}
}

char *fill_str(int count, t_node **current_node)
{
	char *str_tmp;
	int	i;
	int	j;

	j = 0;
	str_tmp = malloc(sizeof(char) * (BUFFER_SIZE * count) + 1);
	while(!*current_node)	
	{
		i = 0;
		while(*current_node->str[i])
		{
			str_tmp[j] = *current_node->str[i];
			j++;
			i++;
		}
		*current_node = *current_node->next;
	}
	str_tmp[j] = '\0';
	return (str_tmp);
}

char *get_next_line(int fd)
{
	static t_node	*heap = NULL;
	char *str_return;
	int	count;

	if(!fd || fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	count = 0;
	create_node_list(&heap, fd, &count);
	str_return = fill_str(count, &heap);
	//print_node(heap);
	//free_list(&heap);
	free(heap);
	return (str_return);
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
//		printf("%s", str);
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
