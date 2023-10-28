/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvath <dhorvath@hive.student.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:45:52 by dhorvath          #+#    #+#             */
/*   Updated: 2023/10/28 22:59:20 by dhorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin_with_free(char *tocheck, char *buf, int buf_len);
char	*ft_substr(char *str, int start, int len, char *buf);
int		get_char_index(char *s);
char	*free_stuff(char *buf, char *to_check);

int		ft_l_strlen(char *s);
int		ft_r_strlen(char *s, int i);
int		ft_strlen(char *s);
void	*malloc_wrapper(size_t bytes);

#endif