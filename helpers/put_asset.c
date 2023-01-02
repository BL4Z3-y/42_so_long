/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:45:29 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/02 10:00:11 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_background(t_init *game)
{
	int	x;
	int	y;

	x = 32;
	y = 32;
	if (game)
	while (y < game->window_h - 64)
	{
		x = 32;
		while (x < game->window_w - 64)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->background, x, y);
			x += 64;
		}
		y += 64;
	}
}

void	put_border(t_init *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->corner, 32, 32);
	mlx_put_image_to_window(game->mlx, game->win, game->corner, game->window_w - 64, 32);
	mlx_put_image_to_window(game->mlx, game->win, game->corner, 32, game->window_h - 64);
	mlx_put_image_to_window(game->mlx, game->win, game->corner, game->window_w - 64, game->window_h - 64);
	mlx_put_image_to_window(game->mlx, game->win, game->side1, 32, 64);
	mlx_put_image_to_window(game->mlx, game->win, game->side2, 32, game->window_h - 96);
	mlx_put_image_to_window(game->mlx, game->win, game->side1, game->window_w - 64, 64),
	mlx_put_image_to_window(game->mlx, game->win, game->side2, game->window_w - 64, game->window_h - 96),
	mlx_put_image_to_window(game->mlx, game->win, game->top1, 64, 32);
	mlx_put_image_to_window(game->mlx, game->win, game->top2, game->window_w - 96, 32);
	mlx_put_image_to_window(game->mlx, game->win, game->top1, 64, game->window_h - 64);
	mlx_put_image_to_window(game->mlx, game->win, game->top2, game->window_w - 96, game->window_h - 64);
	put_border2(game);
}

void	put_border2(t_init *game)
{
	int	x;
	int	y;

	x = 96;
	y = 96;
	while (x < game->window_w - 96)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->top3, x, 32);
		mlx_put_image_to_window(game->mlx, game->win, game->top3, x, game->window_h - 64);
		x += 32;
	}
	while (y < game->window_h - 96)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->side3, 32, y);
		mlx_put_image_to_window(game->mlx, game->win, game->side3, game->window_w - 64, y);
		y += 32;
	}			
	if (game->count_c == 0)
		game->exit = game->exit_o;
}

void	put_wall(t_init *game)
{
	int	x;
	int	y;
	int	i;
	int	j;
	
	i = 1;
	j = 1;
	x = 64;
	y = 64;
	while (i < game->hei - 1)
	{
		x = 64;
		j = 1;	
		while (j < game->wid - 1)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x, y);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->skull, x, y);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}
void	put_player(t_init *game)
{
	game->exit = game->exit_o;
	mlx_put_image_to_window(game->mlx, game->win, game->exit, game->exit_x * 32 + 32, game->exit_y * 32 + 32);
	mlx_put_image_to_window(game->mlx, game->win, game->player, game->player_x * 32 + 32, game->player_y * 32 + 32);
}
