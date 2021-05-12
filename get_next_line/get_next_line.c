/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taichika <taichika@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:55:31 by taichika          #+#    #+#             */
/*   Updated: 2021/05/12 18:32:27 by taichika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_next_line(int fd, char **line)
{
	static char	pre_line[BUFFER_SIZE];
	char	*new_line;
	char	buf[BUFFER_SIZE];
	long	line_size;
	long	limit;
	long pre_line_size;

	limit = 1024;
	*line = (char *)malloc(sizeof(char) * limit);
	line_size = 0;
	pre_line_size = 0;
	line_size += get_put_num(buf, read(fd, buf, BUFFER_SIZE), line_size);
	while(line_size - pre_line_size == BUFFER_SIZE)
	{
		if (pre_line_size / limit < line_size / limit)
		{
			new_line = (char *)malloc(sizeof(char) *
				(line_size + limit - 1) / limit * limit);
			ft_memcpy(new_line, *line, pre_line_size);
			ft_memcpy(new_line + pre_line_size, buf, line_size - pre_line_size);
			*line = new_line;
			free(*line);
		}
		pre_line_size = line_size;
		line_size += get_put_num(buf, read(fd, buf, BUFFER_SIZE), line_size);
	}
	ft_memcpy(pre_line, buf + (line_size - pre_line_size),
		line_size - pre_line_size);
		
}

int	check_line_num(char *buf, int num)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < num)
	{
		if (buf[i++] == '\n')
			cnt++;
	}
	return (cnt);
}

add_line(char *buf, int buf_size, long line_size, long limits, char line)
{
	int i;
	char *larger_line;

	i = 0;
	while (buf[i] != '\0')
		i++;
	if(line_size / limits < (i + line_size) / limits)
	{
		larger_line = (char *)malloc(sizeof(char) *
			(line_size + i + limits - 1) / limits * limits);
	
	}
		
	ft_memcpy(line, buf, i);
}

get_put_num(char *buf, int buf_size, long line_size)
{
	int i;
	char *larger_line;

	i = 0;
	while (buf[i] != '\n')
		i++;
	return(i);
}
