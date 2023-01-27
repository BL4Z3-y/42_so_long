/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:41:13 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/05 20:59:36 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill_one(int x, int y, char **map, t_init *game)
{
	if (map[y][x] != 'P' && map[y][x] != '0' && map[y][x] != 'C')
		return ;
	map[y][x] = 'X';
	flood_fill_one(x + 1, y, map, game);
	flood_fill_one(x, y + 1, map, game);
	flood_fill_one(x, y - 1, map, game);
	flood_fill_one(x - 1, y, map, game);
}

void	flood_fill_two(int x, int y, char **map, t_init *game)
{
	if (map[y][x] != 'X' && map[y][x] != 0 && map[y][x] != 'E')
		return ;
	map[y][x] = 'Y';
	flood_fill_two(x, y - 1, map, game);
	flood_fill_two(x + 1, y, map, game);
	flood_fill_two(x, y + 1, map, game);
	flood_fill_two(x - 1, y, map, game);
}

void	fill_check_one(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				free_ft(map);
				ft_error(2);
			}	
			j++;
		}
		i++;
	}
}

void	fill_check_two(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				free_ft(map);
				ft_error(2);
			}
			j++;
		}
		i++;
	}
}

void	path_check(t_init *game)
{
	char	**map_2;

	map_2 = dup_map(game);
	flood_fill_one(game->player_x, game->player_y, map_2, game);
	fill_check_one(map_2);
	flood_fill_two(game->player_x, game->player_y, map_2, game);
	fill_check_two(map_2);
	free_ft(map_2);
}
