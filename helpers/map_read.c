/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:10:45 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/26 14:34:11 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char **map_read(char *path)
{
	char	*str;
	char	*tmp;
	char	**map;
	int		fd;

	if (!ft_strstr(path, ".ber"))
		ft_error(1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(1);
	str = get_next_line(fd);
	tmp = NULL;
	while (str)
	{
		tmp = ft_strjoin(tmp, str);
		str = get_next_line(fd);
	}
	map = ft_split(tmp, '\n');
	return (map);
}