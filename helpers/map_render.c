/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:19:05 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/28 15:44:50 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_render(t_init *game, t_wxpm *asset)
{
	terrain(game->mlx, asset);
	put_background(game, asset);
	put_border(game, asset);
	put_wall_cherries(game, asset);
}

void	player_mov(t_init *game, t_wxpm *asset, int keycode)
{
	if (keycode == 13 || keycode == 126)
	if (keycode == 0 || keycode == 124)
	if (keycode == 2 || keycode == 123)
	if (keycode == 1 || keycode == 125)
}