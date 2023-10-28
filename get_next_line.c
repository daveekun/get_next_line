/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:39:46 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/28 23:33:00 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUF_SIZE
# define BUF_SIZE 100
#endif

/*
if has in buffer
	return first line from it, shorten static var
while can read(fd, buf, size)
	append to tocheck
	if has '\n' in tocheck
		return first line from it, shorten static var
return to_check

always 0 terminate
careful with free
*/

char	*get_next_line(int fd)
{
	static char	*to_check = 0;
	char		*buf;
	int			just_read;
	int			index;

	buf = malloc_wrapper(BUF_SIZE);
	index = get_char_index(to_check);
	if (index != -1 || !buf)
	{
		to_check += index + 1;
		return (ft_substr(to_check - index - 1, 0, index + 1, buf));
	}
	just_read = read(fd, buf, BUF_SIZE);
	while (just_read)
	{
		to_check = ft_strjoin_with_free(to_check, buf, just_read);
		index = get_char_index(to_check);
		if (index != -1)
		{
			to_check += index + 1;
			return (ft_substr(to_check - index - 1, 0, index + 1, buf));
		}
		just_read = read(fd, buf, BUF_SIZE);
	}
	return (0);
}

char	*ft_strjoin_with_free(char *tocheck, char *buf, int buf_len)
{
	char	*res;
	char	*save_for_free;
	int		i;
	int		j;

	save_for_free = tocheck;
	res = malloc(ft_r_strlen(tocheck, 0) + buf_len + 1);
	if (!res)
		return (free_stuff(buf, tocheck));
	i = 0;
	while (tocheck && tocheck[i])
	{
		res[i] = tocheck[i];
		i++;
	}
	j = 0;
	while (j < buf_len)
	{
		res[i + j] = buf[j];
		j++;
	}
	res[i + j] = 0;
	if (save_for_free)
		free(save_for_free);
	return (res);
}

char	*ft_substr(char *str, int start, int len, char *buf)
{
	int		i;
	char	*res;

	if (!buf)
		return (free_stuff(str, buf));
	if (!str)
		return (0);
	i = 0;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (free_stuff(str, buf));
	while (str[start + i] && i < len)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}

int	get_char_index(char *s)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*free_stuff(char *buf, char *to_check)
{
	if (buf)
		free(buf);
	if (to_check)
		free(to_check);
	return (0);
}
