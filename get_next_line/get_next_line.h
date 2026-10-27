/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.h                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: mgiraldi <marvin@42.fr>                       +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/20 18:23:20 by mgiraldi       #+#    #+#                */
/*   Updated: 2026/10/20 18:23:22 by mgiraldi       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		str_len(char *l);
char	*buff_append(char *src, char *dest);
char	*str_append(char *src, char *dest);
int		str_char(char *src, char c);

#endif
