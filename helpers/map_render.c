/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:19:05 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/02 11:25:14 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_render(t_init *game)
{
	put_background(game);
	put_border(game);
	if (game->count_c == 0)
		game->map[game->exit_y][game->exit_x] = '0';
	put_wall(game);
}

void	player_mov(t_init *game, int keycode)
{
	map_render(game);
	if ((keycode == 13 || keycode == 126) && (check_up(game) == 1))
	{
			ft_printf("Player has moved upward, Total moves : %d\n", ++game->moves);
			game->player = game->player_u;
			game->player_y--;
	}	
	if ((keycode == 1 || keycode == 125) && (check_down(game) == 1))
	{
			ft_printf("Player has moved updown, Total moves : %d\n", ++game->moves);
			game->player = game->player_d;
			game->player_y++;
	}
	if ((keycode == 0 || keycode == 123) && (check_left(game) == 1))
	{
			ft_printf("Player has moved to the left, Total moves : %d\n", ++game->moves);
			game->player = game->player_l;
			game->player_x--;
	}
	if ((keycode == 2 || keycode == 124) && (check_right(game) == 1))
	{
			ft_printf("Player has moved to the right, Total moves : %d\n", ++game->moves);
			game->player = game->player_r;
			game->player_x++;
	}		
	if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		exit(0);
	mlx_put_image_to_window(game->mlx, game->win, game->player, game->player_x * 32 + 32, game->player_y * 32 + 32);
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