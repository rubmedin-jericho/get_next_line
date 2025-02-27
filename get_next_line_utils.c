/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:02:05 by rubmedin          #+#    #+#             */
/*   Updated: 2025/02/24 18:02:22 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	free_list(t_node *node)
{
	t_node *tmp_node;
	
	while(node)
	{
		tmp_node = node;
		node = node->next;
		//free(tmp_node->str);
		free(tmp_node);
	}
}

#include <stdio.h>
void	switch_node(t_node **list, int node_count)
{
	t_node	*first_node;
	t_node	*tmp_node;	
	t_node	*current_node;

	tmp_node = *list;
	first_node = *list;
	current_node = *list;
	printf("first_node: %s\n", first_node->str);
	while(node_count > 0)
	{	
		printf("current: %s\n", current_node->str);
		current_node = current_node->next;
		node_count--;
	}
	while((tmp_node->next)->str != current_node->str)
	{
		printf("tmp_node: %s\n", tmp_node->str);
		tmp_node = tmp_node->next;
	}
	tmp_node->next = NULL;
	*list = current_node;
	free_list(first_node);
}
