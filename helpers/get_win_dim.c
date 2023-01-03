/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_dim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:20:18 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/03 16:43:58 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_win_dim(t_init *game)
{
	game->x = 0;
	game->window_h = 0;
	game->y = 0;
	game->window_w = 0;
	while (game->map[game->y])
	{
		game->window_h++;
		game->y++;
	}
	game->y = 0;
	while (game->map[game->y][game->x])
	{
		game->window_w++;
		game->x++;
	}
	game->hei = game->window_h;
	game->wid = game->window_w;
	game->window_w *= 32;
	game->window_h *= 32;
	game->window_w += 64;
	game->window_h += 64;
}
