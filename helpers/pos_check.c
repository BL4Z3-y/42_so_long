/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:58:24 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/03 17:06:45 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_up(t_init *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1' &&
		game->map[game->player_y - 1][game->player_x] != 'E')
		return (1);
	return (0);
}

int	check_down(t_init *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1' &&
		game->map[game->player_y + 1][game->player_x] != 'E')
		return (1);
	return (0);
}

int	check_right(t_init *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1' &&
		game->map[game->player_y][game->player_x + 1] != 'E')
		return (1);
	return (0);
}

int	check_left(t_init *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1' &&
		game->map[game->player_y][game->player_x - 1] != 'E')
		return (1);
	return (0);
}
