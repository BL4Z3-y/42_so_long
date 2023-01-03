/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:59:28 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/03 17:06:01 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_check(t_init *game)
{
	get_pos(game);
	if (game->count_c < 1 || game->count_e != 1 || game->count_p != 1)
		ft_error (2);
	game->i = 1;
	game->j = 1;
	game->x = 64;
	game->y = 64;
}

void	get_pos(t_init *game)
{
	while (game->i < game->hei - 1)
	{
		game->x = 64;
		game->j = 1;
		while (game->j < game->wid - 1)
		{
			if (game->map[game->i][game->j] == 'C')
				game->count_c++;
			if (game->map[game->i][game->j] == 'E')
				game->count_e++;
			if (game->map[game->i][game->j] == 'P')
			{
				game->player_x = game->j;
				game->player_y = game->i;
				game->count_p++;
			}
			game->j++;
			game->x += 32;
		}
		game->i++;
		game->y += 32;
	}
}
