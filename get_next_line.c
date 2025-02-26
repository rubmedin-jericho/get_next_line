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

void	insert_node(t_node **current_node, t_node *new_node)
{
	t_node *node_tmp;

	if(!*current_node)	
	{
		*current_node = new_node;
		return ;
	}	
	node_tmp = *current_node;
	while(node_tmp->next != NULL)
		node_tmp = node_tmp->next;
	node_tmp->next = new_node;
}

t_node	*create_node(char *words)
{
	t_node *new_node;
	long		i;

	i = 0;
	new_node = malloc(sizeof(t_node));
	if(!new_node)
		return NULL;
	while(words[i] && i < BUFFER_SIZE)
	{
		new_node->str[i] = words[i];
		i++;
	}
	new_node->str[i] = '\0';
	new_node->next = NULL;
	return (new_node);
}

int	create_node_list(t_node **node, int fd, int *count)
{
	char	*buff_tmp;
	int		nbr_read;	
	int		i = 0;
	t_node	*new_node;

	buff_tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ft_bzero(buff_tmp, BUFFER_SIZE);
	nbr_read = 1;
	while(nbr_read > 0)
	{			
		nbr_read = read(fd, buff_tmp, BUFFER_SIZE);
		if(nbr_read == -1)
			return (1);
		buff_tmp[nbr_read] = '\0';
		new_node = create_node(buff_tmp);	
		insert_node(node, new_node);
		*count += 1;
		i++;
	}
	return (0);
}

char *fill_str(int count, t_node *current_node, int *node_count)
{
	char *str_tmp;
	int	i;
	int	j;

	j = 0;
	str_tmp = malloc(sizeof(char) * (BUFFER_SIZE * count) + 2);
	if(!str_tmp)
		return (NULL);
	while(current_node)	
	{
		i = 0;
		*node_count += 1;
		while(current_node->str[i] && current_node->str[i] != '\n')
			str_tmp[j++] = current_node->str[i++];
		if(current_node->str[i] == '\n')
			break;
		current_node = current_node->next;
	}
	str_tmp[j] = '\n';
	str_tmp[++j] = '\0';
	return (str_tmp);
}

char *get_next_line(int fd)
{
	static t_node	*heap = NULL;
	char *str_return;
	int	count;
	int	node_count;

	if(!fd || fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	count = 0;
	node_count = 0;
	if(create_node_list(&heap, fd, &count))
		return (NULL);
	printf("BUFFER_SIZE: %i\n", BUFFER_SIZE);
	str_return = fill_str(count, heap, &node_count);
	if(node_count > 0)
		switch_node(&heap, node_count);
	//print_node(heap);
	//free_list(&heap);
//	free(heap);
	return (str_return);
}

int	main()
{
	int	fd;
	char *str;
	
	fd = open("test", O_RDONLY);
	str = get_next_line(fd);
	printf("str: %s", str);
//	str = get_next_line(fd);
//	printf("str: %s", str);
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
