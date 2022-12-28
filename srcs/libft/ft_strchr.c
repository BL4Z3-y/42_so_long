/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:41:40 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/27 19:20:40 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)&str[i]);
	i = 0;
	while (str[i] != (char)c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (0);
	return ((char *)&str[i]);
}
