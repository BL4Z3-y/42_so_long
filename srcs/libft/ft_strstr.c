/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:09:33 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/31 22:21:16 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	j = ft_strlen(str) - 5;
	i = 0;
	if (!to_find[j])
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (!to_find[j + 1])
				return (&str[i]);
				j++;
		}
		i++;
	}
	return (0);
}
