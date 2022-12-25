/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:35:44 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/25 20:05:53 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		init	*game;
		
		game = malloc(sizeof(init));
		game->map = map_read(av[1]);
		get_win_dim(game->map, &game->window_h, &game->window_w);
		











		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, game->window_w, game->window_h, "so_long");
		mlx_loop(game->mlx);
	}
	ft_error(3);
}