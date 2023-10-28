/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:43:55 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/28 23:30:13 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUF_SIZE
# define BUF_SIZE 1
#endif

/*
if has buffer
	return first line from it, shorten static var
while can read(fd, buf, size)
	append to tocheck
	if has in tocheck
		return first line from it, shorten static var
*/

int	ft_l_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!s[i + 1])
			return (i + 1);
		else if (!s[i + 2])
			return (i + 2);
		else if (!s[i + 3])
			return (i + 3);
		else if (!s[i + 4])
			return (i + 4);
		else if (!s[i + 5])
			return (i + 5);
		else if (!s[i + 6])
			return (i + 6);
		else if (!s[i + 7])
			return (i + 7);
		else if (!s[++i + 7])
			return (i + 7);
	}
	return (i);
}

int	ft_r_strlen(char *s, int i)
{
	if (!s)
		return (0);
	if (*s)
		return (ft_r_strlen(s + 1, i + 1));
	else
		return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i++])
		;
	return (i);
}

void	*malloc_wrapper(size_t bytes)
{
	if (BUF_SIZE)
		return (malloc(bytes));
	else
		return (0);
}
