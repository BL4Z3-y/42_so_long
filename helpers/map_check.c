/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:59:28 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/05 20:52:25 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_check(t_init *game)
{
	get_pos(game);
	if (game->count_c < 1 || game->count_e != 1 || game->count_p != 1)
		ft_error (2);
	check_rec(game);
	check_wall(game);
	path_check(game);
}

void	get_pos(t_init *game)
{
	while (game->i < game->hei - 1)
	{
		game->j = 1;
		while (game->j < game->wid - 1)
		{
			if (game->map[game->i][game->j] == 'C')
				game->count_c++;
			else if (game->map[game->i][game->j] == 'E')
			{
				game->count_e++;
				game->exit_x = game->j;
				game->exit_y = game->i;
			}
			else if (game->map[game->i][game->j] == 'P')
			{
				game->player_x = game->j;
				game->player_y = game->i;
				game->count_p++;
			}
			game->j++;
		}
		game->i++;
	}
}

void	check_rec(t_init *game)
{
	game->i = 0;
	while (game->map[game->i])
	{
		if (ft_strlen(game->map[0]) == ft_strlen(game->map[game->i]))
			game->i++;
		else
			ft_error(2);
	}
	game->i = 0;
	game->j = 0;
	while (game->i < game->hei)
	{
		game->j = 0;
		while (game->j < game->wid)
		{
			if (game->map[game->i][game->j] != '1' &&
				game->map[game->i][game->j] != '0' &&
				game->map[game->i][game->j] != 'P' &&
				game->map[game->i][game->j] != 'C' &&
				game->map[game->i][game->j] != 'E')
				ft_error(2);
			game->j++;
		}
		game->i++;
	}
}

void	check_wall(t_init *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[0][x] && game->map[game->hei - 1][x])
	{
		if (game->map[0][x] != '1' || game->map[game->hei - 1][x] != '1')
			ft_error(2);
		x++;
	}
	y = 1;
	while (y < game->hei - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][game->wid - 1] != '1')
			ft_error(2);
		y++;
	}
}
