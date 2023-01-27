/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:19:05 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/05 03:49:04 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_render(t_init *game)
{
	put_background(game);
	put_border(game);
	if (game->count_c == 0)
		game->map[game->exit_y][game->exit_x] = '0';
	game->i = 1;
	game->j = 1;
	game->x = 64;
	game->y = 64;
	put_wall(game);
}

void	player_mov(t_init *game, int keycode)
{
	map_render(game);
	if ((keycode == 13 || keycode == 126) && (check_up(game) == 1))
		move_up(game);
	if ((keycode == 1 || keycode == 125) && (check_down(game) == 1))
		move_down(game);
	if ((keycode == 0 || keycode == 123) && (check_left(game) == 1))
		move_left(game);
	if ((keycode == 2 || keycode == 124) && (check_right(game) == 1))
		move_right(game);
	if (game->player_x == game->exit_x && game->player_y == game->exit_y)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player,
		game->player_x * 32 + 32, game->player_y * 32 + 32);
}

void	step_count(t_init *game)
{
	char	*count;

	count = ft_itoa(game->moves);
	mlx_put_image_to_window(game->mlx, game->win, game->step_c, 0, 0);
	mlx_string_put(game->mlx, game->win, 30, 6, 0xffffff, count);
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->count_c--;
		game->map[game->player_y][game->player_x] = '0';
	}
	free(count);
}
