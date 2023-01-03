/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:45:29 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/03 17:08:56 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_background(t_init *game)
{
	game->x = 32;
	game->y = 32;
	while (game->y < game->window_h - 64)
	{
		game->x = 32;
		while (game->x < game->window_w - 64)
		{
			mlx_put_image_to_window(game->mlx,
				game->win, game->background, game->x, game->y);
			game->x += 64;
		}
		game->y += 64;
	}
}

void	put_border(t_init *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->corner, 32, 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->corner, game->window_w - 64, 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->corner, 32, game->window_h - 64);
	mlx_put_image_to_window(game->mlx, game->win,
		game->side1, 32, 64);
	mlx_put_image_to_window(game->mlx, game->win,
		game->side2, 32, game->window_h - 96);
	mlx_put_image_to_window(game->mlx, game->win,
		game->side1, game->window_w - 64, 64),
	mlx_put_image_to_window(game->mlx, game->win,
		game->side2, game->window_w - 64, game->window_h - 96),
	mlx_put_image_to_window(game->mlx, game->win,
		game->top1, 64, 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->top2, game->window_w - 96, 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->top1, 64, game->window_h - 64);
	mlx_put_image_to_window(game->mlx, game->win,
		game->top2, game->window_w - 96, game->window_h - 64);
	put_border2(game);
}

void	put_border2(t_init *game)
{
	game->x = 96;
	game->y = 96;
	while (game->x < game->window_w - 96)
	{
		mlx_put_image_to_window(game->mlx,
			game->win, game->top3, game->x, 32);
		mlx_put_image_to_window(game->mlx,
			game->win, game->top3, game->x, game->window_h - 64);
		game->x += 32;
	}
	while (game->y < game->window_h - 96)
	{
		mlx_put_image_to_window(game->mlx,
			game->win, game->side3, 32, game->y);
		mlx_put_image_to_window(game->mlx,
			game->win, game->side3, game->window_w - 64, game->y);
		game->y += 32;
	}			
}

void	put_wall(t_init *game)
{
	while (game->i < game->hei - 1)
	{
		game->x = 64;
		game->j = 1;
		while (game->j < game->wid - 1)
		{
			if (game->map[game->i][game->j] == 'E')
			{
				game->exit_x = game->j;
				game->exit_y = game->i;
			}
			if (game->map[game->i][game->j] == '1')
				mlx_put_image_to_window(game->mlx,
					game->win, game->wall, game->x, game->y);
			if (game->map[game->i][game->j] == 'C')
				mlx_put_image_to_window(game->mlx,
					game->win, game->skull, game->x, game->y);
			game->j++;
			game->x += 32;
		}
		game->i++;
		game->y += 32;
	}
}

void	put_player(t_init *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->exit,
		game->exit_x * 32 + 32, game->exit_y * 32 + 32);
	mlx_put_image_to_window(game->mlx, game->win, game->player,
		game->player_x * 32 + 32, game->player_y * 32 + 32);
}
