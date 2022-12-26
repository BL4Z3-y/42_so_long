/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_asset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:45:29 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/26 23:54:12 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_background(void *mlx, void *win, void *img, int w_hei, int w_wid, int m_wid)
{
	int	x;
	int	y;

	x = 32;
	y = 32;
	if (m_wid % 2 == 0)
		w_wid -= 32;
	if (m_wid % 2 != 0)
		w_wid -= 64;
	while (y < w_hei - 64)
	{
		x = 32;
		while (x < w_wid)
		{
			
			mlx_put_image_to_window(mlx, win, img, x, y);
			x += 64;
		}
		y += 64;
	}
}

void	put_border(void *mlx, void *win, void *corner, void *side1, void *side2, void *side3, void *top1, void *top2, void *top3, int hei, int wid)
{
	//CORNERS
	//up
	mlx_put_image_to_window(mlx, win, corner, 32, 32);
	mlx_put_image_to_window(mlx, win, corner, wid - 64, 32);
	//down
	mlx_put_image_to_window(mlx, win, corner, 32, hei - 64);
	mlx_put_image_to_window(mlx, win, corner, wid - 64, hei - 64);
	//SIDES
	//up
	mlx_put_image_to_window(mlx, win, side1, 32, 64);
	mlx_put_image_to_window(mlx, win, side2, 32, hei - 96);
	//down
	mlx_put_image_to_window(mlx, win, side1, wid - 64, 64),
	mlx_put_image_to_window(mlx, win, side2, wid - 64, hei - 96),
	//TOP
	//up
	mlx_put_image_to_window(mlx, win, top1, 64, 32);
	mlx_put_image_to_window(mlx, win, top2, wid - 96, 32);
	//down
	mlx_put_image_to_window(mlx, win, top1, 64, hei - 64);
	mlx_put_image_to_window(mlx, win, top2, wid - 96, hei - 64);
	//REMAINING
	put_border2(mlx, win, side3, top3, hei, wid);
}

void	put_border2(void *mlx, void *win, void *side3, void *top3, int hei, int wid)
{
	int	x;
	int	y;

	(void)side3;
	x = 96;
	y = 96;
	while (x < wid - 96)
	{
		mlx_put_image_to_window(mlx, win, top3, x, 32);
		mlx_put_image_to_window(mlx, win, top3, x, hei - 64);
		x += 32;
	}
	while (y < hei - 96)
	{
		mlx_put_image_to_window(mlx, win, side3, 32, y);
		mlx_put_image_to_window(mlx, win, side3, wid - 64, y);
		y += 32;
	}
}

void	put_wall(void *mlx, void *win, void *wall, char **map, int hei, int wid)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 1;
	j = 1;
	x = 64;
	y = 64;
	while (i < hei - 1)
	{
		x = 64;
		j = 1;	
		while (j < wid - 1)
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, wall, x, y);
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}