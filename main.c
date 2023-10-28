/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:26:42 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/28 23:29:07 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("poem", O_RDWR);
	res = get_next_line(fd);
	while (res)
	{
		printf("%s", res);
		res = get_next_line(fd);
	}
}
