/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:09:50 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/03 16:20:47 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	door(t_init *game)
{
	game->exit_c = mlx_xpm_file_to_image(game->mlx,
			"./textures/Door/exit_closed.xpm", &game->width, &game->height);
	game->exit_o1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/Door/exit_opened1.xpm", &game->width, &game->height);
	game->exit_o2 = mlx_xpm_file_to_image(game->mlx,
			"./textures/Door/exit_opened2.xpm", &game->width, &game->height);
	game->exit_o3 = mlx_xpm_file_to_image(game->mlx,
			"./textures/Door/exit_opened3.xpm", &game->width, &game->height);
	game->exit_o4 = mlx_xpm_file_to_image(game->mlx,
			"./textures/Door/exit_opened4.xpm", &game->width, &game->height);
	game->exit = game->exit_c;
}

void	other(t_init *game)
{
	game->corner = mlx_xpm_file_to_image(game->mlx,
			"./textures/Border/corner.xpm", &game->width, &game->height);
	game->background = mlx_xpm_file_to_image(game->mlx,
			"./textures/Background/background.xpm", &game->widbg, &game->heibg);
}

void	border(t_init *game)
{
	game->side1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/Border/side1.xpm", &game->width, &game->height);
	game->side2 = mlx_xpm_file_to_image(game->mlx,
			"./textures/Border/side2.xpm", &game->width, &game->height);
	game->side3 = mlx_xpm_file_to_image(game->mlx,
			"./textures/Border/side3.xpm", &game->width, &game->height);
	game->top1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/Border/top1.xpm", &game->width, &game->height);
	game->top2 = mlx_xpm_file_to_image(game->mlx,
			"./textures/Border/top2.xpm", &game->width, &game->height);
	game->top3 = mlx_xpm_file_to_image(game->mlx,
			"./textures/Border/top3.xpm", &game->width, &game->height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall/wall.xpm", &game->width, &game->height);
}

void	player(t_init *game)
{
	game->step_c = mlx_xpm_file_to_image(game->mlx,
			"./textures/step_c/step_c.xpm", &game->width, &game->height);
	game->skull = mlx_xpm_file_to_image(game->mlx,
			"./textures/Collectible/skull.xpm", &game->width, &game->height);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./textures/Player/grave.xpm", &game->width, &game->height);
	game->player_u = mlx_xpm_file_to_image(game->mlx,
			"./textures/Player/up.xpm", &game->width, &game->height);
	game->player_d = mlx_xpm_file_to_image(game->mlx,
			"./textures/Player/down.xpm", &game->width, &game->height);
	game->player_l = mlx_xpm_file_to_image(game->mlx,
			"./textures/Player/left.xpm", &game->width, &game->height);
	game->player_r = mlx_xpm_file_to_image(game->mlx,
			"./textures/Player/right.xpm", &game->width, &game->height);
}

void	terrain(t_init *game)
{
	game->height = 32;
	game->width = 32;
	game->heibg = 64;
	game->widbg = 64;
	door(game);
	player(game);
	other(game);
	border(game);
}
