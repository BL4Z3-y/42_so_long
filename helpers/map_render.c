/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:19:05 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/29 15:38:12 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_render(t_init *game)
{
	terrain(game);
	put_background(game);
	put_border(game);
	put_wall_cherries(game);
}

void	player_mov(t_init *game, int keycode)
{
	map_render(game);
	if ((keycode == 13 || keycode == 126) && (game->map[game->player_y - 1][game->player_x] != '1'))
	{
		ft_printf("Player has moved upward, Total moves : %d\n", ++game->moves);
		game->player_y--;
	}	
	if ((keycode == 1 || keycode == 125) && (game->map[game->player_y + 1][game->player_x] != '1'))
	{
		ft_printf("Player has moved updown, Total moves : %d\n", ++game->moves);
		game->player_y++;
	}
	if ((keycode == 2 || keycode == 123) && (game->map[game->player_y][game->player_x - 1] != '1'))
	{
		ft_printf("Player has moved to the right, Total moves : %d\n", ++game->moves);
		game->player_x--;
	}
	if ((keycode == 0 || keycode == 124) && (game->map[game->player_y][game->player_x + 1] != '1'))
	{
		ft_printf("Player has moved to the left, Total moves : %d\n", ++game->moves);
		game->player_x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->grave, game->player_x * 32 + 32, game->player_y * 32 + 32);
}

void	step_count(t_init *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->step_c, 0, 0);
	mlx_string_put(game->mlx, game->win, 30, 6, 0xffffff, ft_itoa(game->moves));
}