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
void	fill_buff(int fd, char **buff_tmp, int *count_read)
{
	char *str_tmp;
	int	count_read;

	count_read = 0;
	*buff_tmp = malloc(sizeof(char) * BUFFER_SIZE + 1)
	if(!(*buff_tmp))
		return NULL;
	*count_read = read(fd, *buff_tmp, BUFFER_SIZE);
	(*buff_tmp)[count_read] = '\0';
}

void	cpy_str()
{

}

void	cut_str(char *buff_static, char *buff)
{
	int	i;
	int	j;

	i = 0;
	while(buff[i] && buff[i] != '\n')
		i++;
	if(i < BUFFER_SIZE)
	{
		j = 0;
		i++;
		while(buff[i])
			buff_static[j++] = buff[i++];
		buff_static[j] = '\n';
		buff_static[j++] = '\0';
	}
}
