/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:35:44 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/03 17:12:53 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_init	*game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_init));
		if (!game)
			return (0);
		map_read(av[1], game);
		initialase(game);
		terrain(game);
		map_render(game);
		put_player(game);
		step_count(game);
		mlx_loop_hook(game->mlx, animate, game);
		mlx_hook(game->win, 2, 0, moves_count, game);
		mlx_hook(game->win, 17, 0, ft_exit, game);
		mlx_loop(game->mlx);
	}
	ft_error(3);
}

int	moves_count(int keycode, t_init *game)
{
	player_mov(game, keycode);
	step_count(game);
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int	ft_exit(t_init *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	animate(t_init *game)
{
	if (game->i == 500)
		game->exit = game->exit_o1;
	if (game->i == 1000)
		game->exit = game->exit_o2;
	if (game->i == 1500)
		game->exit = game->exit_o3;
	if (game->i == 2000)
		game->exit = game->exit_o4;
	if (game->i == 500 || game->i == 1000 || game->i == 1500 || game->i == 2000)
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			game->exit_x * 32 + 32, game->exit_y * 32 + 32);
	if (game->i == 2500)
		game->i = 0;
	game->i++;
	return (game->i);
}

void	initialase(t_init *game)
{
	get_win_dim(game);
	map_check(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->window_w,
			game->window_h, "so_long");
	game->i = 0;
	game->moves = 0;
	game->count_c = 0;
	game->count_e = 0;
	game->count_p = 0;
}
