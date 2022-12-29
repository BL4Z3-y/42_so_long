/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:35:44 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/29 14:58:36 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		t_init	*game;
		
		game = malloc(sizeof(t_init));
		game->map = map_read(av[1]);
		game->moves = 0;
		get_win_dim(game);










		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->window_w, game->window_h, "so_long");
		map_render(game);
		put_player(game);
		mlx_put_image_to_window(game->mlx, game->win, game->grave, game->player_x * 32 + 32, game->player_y * 32 + 32);
		step_count(game);	
		mlx_hook(game->win, 2, 0, moves_count, game);
		mlx_hook(game->win, 17, 0, ft_exit, game);
		mlx_loop(game->mlx);
	}
	ft_error(3);
}
int	moves_count(int keycode, t_init *game)
{
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	player_mov(game, keycode);
	step_count(game);
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}