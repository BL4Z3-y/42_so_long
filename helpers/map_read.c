/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:10:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/01 15:00:13 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void map_read(char *path, t_init *game)
{
	char	*str;
	char	*tmp;
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
		free(str);
		str = get_next_line(fd);
	}
	game->map = ft_split(tmp, '\n');
	free(tmp);
	free(str);
}