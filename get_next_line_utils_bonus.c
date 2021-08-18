/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jukim <jukim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:06:17 by jukim             #+#    #+#             */
/*   Updated: 2021/06/01 13:31:11 by jukim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strncpy(char *dest, char *src, ssize_t a)
{
	ssize_t i;

	i = 0;
	while (i < a)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	ssize_t	s1_len;
	ssize_t	s2_len;
	char	*ptr;

	if (!s2 && !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!ptr)
		return (0);
	ft_strncpy(ptr, s1, s1_len);
	free(s1);
	ft_strncpy(ptr + s1_len, s2, s2_len);
	ptr[s1_len + s2_len] = 0;
	return (ptr);
}

char	*ft_strdup(char *s1)
{
	char	*cp_s1;
	ssize_t	i;

	i = 0;
	cp_s1 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!cp_s1)
		return (NULL);
	while (s1[i])
	{
		cp_s1[i] = s1[i];
		i++;
	}
	cp_s1[i] = 0;
	return (cp_s1);
}
