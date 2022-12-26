/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:09:50 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/26 23:17:31 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	image_to_xpm(void *mlx, void **background, void **corner, void **side1, void **side2, void **side3, void **top1, void **top2, void **top3, void **wall)
{
	int	hei;
	int	wid;
	int	heibg;
	int	widbg;

	hei = 32;
	wid = 32;
	heibg = 64;
	widbg = 64;
	*background = mlx_xpm_file_to_image(mlx, "./textures/Background/background.xpm", &widbg, &heibg);
	*corner = mlx_xpm_file_to_image(mlx, "./textures/Border/corner.xpm", &wid, &hei);
	*side1 = mlx_xpm_file_to_image(mlx, "./textures/Border/side1.xpm", &wid, &hei);
	*side2 = mlx_xpm_file_to_image(mlx, "./textures/Border/side2.xpm", &wid, &hei);
	*side3 = mlx_xpm_file_to_image(mlx, "./textures/Border/side3.xpm", &wid, &hei);
	*top1 = mlx_xpm_file_to_image(mlx, "./textures/Border/top1.xpm", &wid, &hei);
	*top2 = mlx_xpm_file_to_image(mlx, "./textures/Border/top2.xpm", &wid, &hei);
	*top3 = mlx_xpm_file_to_image(mlx, "./textures/Border/top3.xpm", &wid, &hei);
	*wall = mlx_xpm_file_to_image(mlx, "./textures/wall/wall.xpm", &wid, &hei);
}

