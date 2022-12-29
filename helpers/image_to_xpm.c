/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:09:50 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/29 15:38:15 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	terrain(t_init *game)
{
	int	hei;
	int	wid;
	int	heigo;
	int	widgo;
	int	heibg;
	int	widbg;

	hei = 32;
	wid = 32;
	heibg = 64;
	widbg = 64;
	heigo = 70;
	widgo = 300;
	game->background = mlx_xpm_file_to_image(game->mlx, "./textures/Background/background.xpm", &widbg, &heibg);
	game->corner = mlx_xpm_file_to_image(game->mlx, "./textures/Border/corner.xpm", &wid, &hei);
	game->side1 = mlx_xpm_file_to_image(game->mlx, "./textures/Border/side1.xpm", &wid, &hei);
	game->side2 = mlx_xpm_file_to_image(game->mlx, "./textures/Border/side2.xpm", &wid, &hei);
	game->side3 = mlx_xpm_file_to_image(game->mlx, "./textures/Border/side3.xpm", &wid, &hei);
	game->top1 = mlx_xpm_file_to_image(game->mlx, "./textures/Border/top1.xpm", &wid, &hei);
	game->top2 = mlx_xpm_file_to_image(game->mlx, "./textures/Border/top2.xpm", &wid, &hei);
	game->top3 = mlx_xpm_file_to_image(game->mlx, "./textures/Border/top3.xpm", &wid, &hei);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall/wall.xpm", &wid, &hei);
	game->step_c = mlx_xpm_file_to_image(game->mlx, "./textures/step_c/step_c.xpm", &wid, &hei);
	game->game_over = mlx_xpm_file_to_image(game->mlx, "./textures/GO/game_over.xpm", &widgo, &heigo);
	game->cherrie = mlx_xpm_file_to_image(game->mlx, "./textures/Collectible/cherrie.xpm", &wid, &hei);
	game->grave = mlx_xpm_file_to_image(game->mlx, "./textures/Player/grave.xpm", &wid, &hei);
	game->exit_c = mlx_xpm_file_to_image(game->mlx, "./textures/Door/exit_closed.xpm", &wid, &hei);
}

