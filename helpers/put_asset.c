/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:45:29 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/28 15:30:45 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_background(t_init *game, t_wxpm *asset)
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
			
			mlx_put_image_to_window(game->mlx, game->win, asset->background, x, y);
			x += 64;
		}
		y += 64;
	}
}

void	put_border(t_init *game, t_wxpm *asset)
{
	//CORNERS
	//up
	mlx_put_image_to_window(game->mlx, game->win, asset->corner, 32, 32);
	mlx_put_image_to_window(game->mlx, game->win, asset->corner, game->window_w - 64, 32);
	//down
	mlx_put_image_to_window(game->mlx, game->win, asset->corner, 32, game->window_h - 64);
	mlx_put_image_to_window(game->mlx, game->win, asset->corner, game->window_w - 64, game->window_h - 64);
	//SIDES
	//up
	mlx_put_image_to_window(game->mlx, game->win, asset->side1, 32, 64);
	mlx_put_image_to_window(game->mlx, game->win, asset->side2, 32, game->window_h - 96);
	//down
	mlx_put_image_to_window(game->mlx, game->win, asset->side1, game->window_w - 64, 64),
	mlx_put_image_to_window(game->mlx, game->win, asset->side2, game->window_w - 64, game->window_h - 96),
	//TOP
	//up
	mlx_put_image_to_window(game->mlx, game->win, asset->top1, 64, 32);
	mlx_put_image_to_window(game->mlx, game->win, asset->top2, game->window_w - 96, 32);
	//down
	mlx_put_image_to_window(game->mlx, game->win, asset->top1, 64, game->window_h - 64);
	mlx_put_image_to_window(game->mlx, game->win, asset->top2, game->window_w - 96, game->window_h - 64);
	//REMAINING
	put_border2(game, asset);
}

void	put_border2(t_init *game, t_wxpm *asset)
{
	int	x;
	int	y;

	x = 96;
	y = 96;
	while (x < game->window_w - 96)
	{
		mlx_put_image_to_window(game->mlx, game->win, asset->top3, x, 32);
		mlx_put_image_to_window(game->mlx, game->win, asset->top3, x, game->window_h - 64);
		x += 32;
	}
	while (y < game->window_h - 96)
	{
		mlx_put_image_to_window(game->mlx, game->win, asset->side3, 32, y);
		mlx_put_image_to_window(game->mlx, game->win, asset->side3, game->window_w - 64, y);
		y += 32;
	}
}

void	put_wall_cherries(t_init *game, t_wxpm *asset)
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
				mlx_put_image_to_window(game->mlx, game->win, asset->wall, x, y);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, asset->cherrie, x, y);
			if (game->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, asset->grave, x, y);
				asset->player_x = j;
				asset->player_y = i;
			}
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}
