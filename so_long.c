/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:35:44 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/26 23:54:03 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		init	*game;
		w_xpm	*asset;
		
		game = malloc(sizeof(init));
		asset = malloc(sizeof(w_xpm));
		game->map = map_read(av[1]);
		get_win_dim(game->map, &game->window_h, &game->window_w, &game->hei, &game->wid);
		












		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->window_w, game->window_h, "so_long");
		image_to_xpm(game->mlx, &asset->background, &asset->corner, &asset->side1, &asset->side2, &asset->side3, &asset->top1, &asset->top2, &asset->top3, &asset->wall);
		put_background(game->mlx, game->win, asset->background, game->window_h, game->window_w, game->wid);
		put_border(game->mlx, game->win, asset->corner, asset->side1, asset->side2, asset->side3, asset->top1, asset->top2, asset->top3, game->window_h, game->window_w);
		put_wall(game->mlx, game->win, asset->wall, game->map, game->hei, game->wid);
		// mlx_string_put(game->mlx, game->win, 16, game->window_h - 25, 0xFFFFFF, "PRESS [ESC] TO EXIT");
		// mlx_string_put(game->mlx, game->win, 5, 5, 0xA60B0B, "Move count: ");
		// mlx_string_put(game->mlx, game->win, 115, 6, 0xA60B0B, ft_itoa(10));
		mlx_loop(game->mlx);
	}
	ft_error(3);
}