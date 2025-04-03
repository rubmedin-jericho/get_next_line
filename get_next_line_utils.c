int	char_in_str(char *str_tmp, int c)
{
	int	i;

	i = 0;
	while(str_tmp[i] != '\n')
	{
		if(str_tmp[i] == c)
			return (1);
		i++;
	}
	return (0);
}



char	*fill_str(char **buff_return, int fd)
{
	int		count_read;
	char	*str_tmp;

	str_tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));	
	if(!(str_tmp))
		return free_str(buff_return);
	count_read = 10;
	while(count_read > 0 && !char_in_str((*buff_str), '\n'))
	{
		count_read = read(fd, (*str_tmp), BUFFER_SIZE)
		if(count_read > 0)
		{
			str_tmp[count_read] = '\0';
			(*buff_str) = ft_strjoin((*buff_str), str_tmp);
		}
	}
	free(str_tmp);
	return ((*buff_return));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	if (!s1)
		ft_strlcpy(str, s2, ft_strlen(s2));
	else if (!s2)
		ft_strlcpy(str, s1, ft_strlen(s1));
	else
	{
		ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
		ft_strlcat(str, s2, ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	}
	str[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
	return (str);
}
