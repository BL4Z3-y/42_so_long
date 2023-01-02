/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:21:16 by yes-slim          #+#    #+#             */
/*   Updated: 2023/01/02 12:06:17 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct initial
{
	void	*mlx;
	void	*win;
	char	**map;
	int		hei;
	int		wid;
	int		window_h;
	int		window_w;
	int		player_x;
	int		player_y;
	void	*background;
	void	*corner;
	void	*side1;
	void	*side2;
	void	*side3;
	void	*top1;
	void	*top2;
	void	*top3;
	void	*wall;
	void	*player;
	void	*player_l;
	void	*player_r;
	void	*player_u;
	void	*player_d;
	void	*step_c;
	void	*skull;
	void	*exit;
	void	*exit_c;
	void	*exit_o;
	int		exit_x;
	int		exit_y;
	int		count_c;
	int		count_p;
	int		count_e;
	int		moves;
}	t_init;

//GNL
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69 
# endif

char	*get_next_line(int fd);
char	*ft_fill(char *str);
char	*ft_remainder(char *str);
char	*ft_read(int fd, char *str);
//-----------------------------------------------------//

//LIBFT
char	*ft_strdup(const char *src);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strstr(char *str, char *to_find);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strstr(char *str, char *to_find);
char	*ft_substr(char const *str, unsigned int start, size_t len);
//-----------------------------------------------------//

//FT_PRINTF
int		ft_printf(const char *str, ...);
void	ft_print_char(char c, int *len);
void	ft_print_str(char *str, int *len);
void	ft_print_nbr(int i, int *len);
void	ft_print_nbr_uns(unsigned int i, int *len);
void	ft_print_hex_up(unsigned int i, int *len);
void	ft_print_hex_low(unsigned int i, int *len);
void	ft_print_adr(unsigned long l, int *len);
//-----------------------------------------------------//

//HELPERS
void	ft_error(int i);
void	map_read(char *path, t_init *game);
void	get_win_dim(t_init *game);
void	put_background(t_init *game);
void	terrain(t_init *game);
void	put_border(t_init *game);
void	put_border2(t_init *game);
void	put_wall(t_init *game);
int		moves_count(int keycode, t_init *game);
int		ft_exit(void);
void	map_render(t_init *game);
void	player_mov(t_init *game, int keycode);
void	step_count(t_init *game);
void	put_player(t_init *game);
int		check_up(t_init *game);
int		check_down(t_init *game);
int		check_right(t_init *game);
int		check_left(t_init *game);
void	map_check(t_init *game);
void	get_pos(t_init *game);
//-----------------------------------------------------//

#endif