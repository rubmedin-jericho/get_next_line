#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd);
int	fill_buff_tmp(int fd, char **buff, int *count_read);
int	cpy_str(char **buff_static, char *buff_tmp, char **buff_return);
#endif
