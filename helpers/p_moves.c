/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:26:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/03 17:04:29 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_init *game)
{
	ft_printf("Player has moved to the right, Total moves : %d\n",
		++game->moves);
	game->player = game->player_r;
	game->player_x++;
}

void	move_left(t_init *game)
{
	ft_printf("Player has moved to the left, Total moves : %d\n",
		++game->moves);
	game->player = game->player_l;
	game->player_x--;
}

void	move_up(t_init *game)
{
	ft_printf("Player has moved upward, Total moves : %d\n",
		++game->moves);
	game->player = game->player_u;
	game->player_y--;
}

void	move_down(t_init *game)
{
	ft_printf("Player has moved updown, Total moves : %d\n",
		++game->moves);
	game->player = game->player_d;
	game->player_y++;
}
