/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:19:05 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/28 14:41:48 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_render(t_init *game, t_wxpm *asset)
{
	terrain(game->mlx, asset);
	put_background(game, asset);
	put_border(game, asset);
	put_wall_cherries(game, asset);
	mlx_put_image_to_window(game->mlx, game->win, asset->step_c, 4, 4);
	mlx_string_put(game->mlx, game->win, 40, 9, 0x931616, ft_itoa(game->moves));
	// mlx_clear_window(game->mlx, game->win);

	// mlx_put_image_to_window(game->mlx, game->win, asset->game_over, (game->window_w / 2 - 160), (game->window_h / 2 - 50));
	// mlx_string_put(game->mlx, game->win, 32, game->window_h - 32, 0xFFFFFF, "PRESS [ESC] TO EXIT");
}
void	map_update(t_init *game, t_wxpm *asset)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_clear_window(game->mlx, game->win);
	map_render(game, asset);
}