/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:58:34 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/25 17:13:13 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(int i)
{
	if (i == 0)
		ft_printf("Invalid file\n");
	if (i == 1)
		ft_printf("File doesn't exist\n");
	if (i == 2)
		ft_printf("Invalid map\n");
	if (i == 3)
		ft_printf("Invalid number of arguments\n");
	exit(0);
}
