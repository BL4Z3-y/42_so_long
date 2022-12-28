/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:35:44 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/28 15:25:20 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		t_init	*game;
		t_wxpm	*asset;
		
		game = malloc(sizeof(t_init));
		asset = malloc(sizeof(t_wxpm));
		game->map = map_read(av[1]);
		game->moves = 0;
		get_win_dim(game);










		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->window_w, game->window_h, "so_long");
		map_render(game, asset);	
		mlx_hook(game->win, 2, 0, moves_count, game);
		mlx_hook(game->win, 17, 0, ft_exit, game);
		mlx_loop(game->mlx);
	}
	ft_error(3);
}
int	moves_count(int keycode, t_init *game, t_wxpm *asset)
{
	(void)asset;
	if (keycode == 0 || keycode == 124)
		ft_printf("Player has moved to the left, Total moves : %d\n", ++game->moves);
	else if (keycode == 2 || keycode == 123)
		ft_printf("Player has moved to the right, Total moves : %d\n", ++game->moves);
	else if (keycode == 13 || keycode == 126)
		ft_printf("Player has moved upward, Total moves : %d\n", ++game->moves);
	else if (keycode == 1 || keycode == 125)
		ft_printf("Player has moved updown, Total moves : %d\n", ++game->moves);
	// map_update(game, asset);
	if (keycode == 53 || keycode == 12)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	return (0);
}

int	ft_exit(void)
{
	exit(0);
}