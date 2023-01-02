/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:59:28 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/02 12:09:08 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_check(t_init *game)
{
	get_pos(game);
	if(game->count_c < 1 || game->count_e != 1 || game->count_p != 1)
		ft_error(2);
		
}

void	get_pos(t_init *game)
{
	int	x;
	int	y;
	int	i;
	int	j;
	
	game->count_c = 0;
	game->count_e = 0;
	game->count_p = 0;
	i = 1;
	j = 1;
	x = 64;
	y = 64;
	while (i < game->hei - 1)
	{
		x = 64;
		j = 1;	
		while (j < game->wid - 1)
		{
			if (game->map[i][j] == 'E')
			{
				game->count_e++;
				game->exit_x = j;
				game->exit_y = i;
			}
			if (game->map[i][j] == 'C')
				game->count_c++;
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				game->count_p++;
			}
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}