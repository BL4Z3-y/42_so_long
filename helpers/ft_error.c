/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:58:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/05 20:54:15 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_printf("Invalid file\n");
	if (i == 2)
		ft_printf("Invalid map\n");
	if (i == 3)
		ft_printf("Invalid number of arguments\n");
	exit(1);
}

char	**dup_map(t_init *game)
{
	int		i;
	char	**map2;

	i = 0;
	map2 = (char **)malloc(sizeof(char *) * (game->hei + 1));
	while (game->map[i])
	{
		map2[i] = ft_strdup(game->map[i]);
		i++;
	}
	map2[i] = NULL;
	return (map2);
}

void	free_ft(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
