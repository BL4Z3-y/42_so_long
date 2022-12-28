/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:09:50 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/28 15:23:22 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	terrain(void *mlx, t_wxpm *asset)
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
	asset->background = mlx_xpm_file_to_image(mlx, "./textures/Background/background.xpm", &widbg, &heibg);
	asset->corner = mlx_xpm_file_to_image(mlx, "./textures/Border/corner.xpm", &wid, &hei);
	asset->side1 = mlx_xpm_file_to_image(mlx, "./textures/Border/side1.xpm", &wid, &hei);
	asset->side2 = mlx_xpm_file_to_image(mlx, "./textures/Border/side2.xpm", &wid, &hei);
	asset->side3 = mlx_xpm_file_to_image(mlx, "./textures/Border/side3.xpm", &wid, &hei);
	asset->top1 = mlx_xpm_file_to_image(mlx, "./textures/Border/top1.xpm", &wid, &hei);
	asset->top2 = mlx_xpm_file_to_image(mlx, "./textures/Border/top2.xpm", &wid, &hei);
	asset->top3 = mlx_xpm_file_to_image(mlx, "./textures/Border/top3.xpm", &wid, &hei);
	asset->wall = mlx_xpm_file_to_image(mlx, "./textures/wall/wall.xpm", &wid, &hei);
	asset->step_c=mlx_xpm_file_to_image(mlx, "./textures/step_c/step_c.xpm", &wid, &hei);
	asset->game_over=mlx_xpm_file_to_image(mlx, "./textures/GO/game_over.xpm", &widgo, &heigo);
	asset->cherrie=mlx_xpm_file_to_image(mlx, "./textures/Collectible/cherrie.xpm", &wid, &hei);
	asset->grave=mlx_xpm_file_to_image(mlx, "./textures/Player/grave.xpm", &wid, &hei);
}

