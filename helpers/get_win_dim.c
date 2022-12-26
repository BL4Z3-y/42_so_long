/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_dim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:20:18 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/26 12:11:59 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_win_dim(char **str, int *size_h, int *size_w , int *hei, int *wid)
{
	int	x;
	int	y;

	x = 0;
	(*size_h) = 0;
	y = 0;
	(*size_w) = 0;
	while (str[y])
	{
		(*size_h)++;
		y++;
	}
	y = 0;
	while (str[y][x])
	{
		(*size_w)++;
		x++;
	}
	*hei = *size_h;
	*wid = *size_w;
	(*size_w) *= 32;
	(*size_h) *= 32;
	(*size_w) += 64;
	(*size_h) += 64;
}