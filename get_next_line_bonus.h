/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habdella <habdella@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:15:13 by habdella          #+#    #+#             */
/*   Updated: 2024/11/03 14:07:35 by habdella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_container(char *contain, char *buff, int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, char c);
char	*ft_strdupnl(char *contain);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
char	*update(char *contain);
char	*get_next_line(int fd);

#endif
