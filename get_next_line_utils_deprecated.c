/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:43:07 by rubmedin          #+#    #+#             */
/*   Updated: 2025/03/25 11:43:16 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//puede fallar por la condicion del while(count_read > 0) si falla arreglar mas adelante.
int	fill_buff_tmp(int fd, char **buff_tmp, int *count_read)
{
	*count_read = 0;
	*buff_tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!(*buff_tmp))
		return (1);
	*count_read = read(fd, *buff_tmp, BUFFER_SIZE);
	if(*count_read < 0)
		return (1);
	(*buff_tmp)[*count_read] = '\0';
	return (0);
}

void buff_static_cpy(char **buff_static, char **buff_return)
{
	int i;

	(*buff_static) = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if((*buff_static == NULL))
		return (NULL);
	(*buff_return) = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if((*buff_return == NULL))
		return (NULL);
	i = 0;
	while((*buff_static)[i] && (*buff_static)[i] != '\n')
	{
		(*buff_return)[i] == (*buff_static)[i];
		i++;
	}
	(*buff_return)[i++] == '\n';
	(*buff_return)[i] == '\0';
	free(buff_static);
}

int	cpy_str(char **buff_static, char *buff_tmp, char **buff_return)
{
	int	i;
	int	j;

	i = 0;
	(*buff_static) = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!(*buff_static))
		return (1);
	(*buff_return) = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!(*buff_return))
		return (1);
	while(buff_tmp[i] && buff_tmp[i] != '\n' && i < BUFFER_SIZE)
	{
		(*buff_return)[i] = buff_tmp[i];
		i++;
	}
	if(buff_tmp[i] == '\n')
		(*buff_return)[i++] = '\n';
	j = 0;
	while(buff_tmp[i] && i < BUFFER_SIZE)
		(*buff_static)[j++] = buff_tmp[i++];
	(*buff_return)[i] = '\0';
	(*buff_static)[j] = '\0';
	return (0);
}
