/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:05:57 by jukim             #+#    #+#             */
/*   Updated: 2021/06/01 13:30:17 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char		*ft_strncpy(char *dest, char *src, ssize_t a);
ssize_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s1);
ssize_t		ft_check_nline(char *buf);
ssize_t		ft_tsplit(char **line, char **buf_save, ssize_t nline_idx);
ssize_t		ft_full_split(char **line, char **buf_save);
int			get_next_line(int fd, char **line);
#endif
