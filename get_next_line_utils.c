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
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < (int)n)
	{
		str[i] = 0;
		i++;
	}
}
#include <stdio.h>
void	switch_node(t_node **list, int node_count)
{
	t_node	*first_node;	
	t_node	*current_node;

	first_node = *list;
	(void)first_node;
	current_node = *list;
	while(node_count > 0)
	{
		current_node = current_node->next;
		node_count--;
	}
	printf("str: %s\n", current_node->str);
}
