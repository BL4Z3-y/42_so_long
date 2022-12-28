/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:21:16 by yes-slim          #+#    #+#             */
/*   Updated: 2022/12/28 15:30:11 by yes-slim         ###   ########.fr       */
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
	int		window_h;
	int		window_w;
	int		hei;
	int		wid;
	int		moves;
}	t_init;

typedef struct xpm
{
	void	*background;
	void	*corner;
	void	*side1;
	void	*side2;
	void	*side3;
	void	*top1;
	void	*top2;
	void	*top3;
	void	*wall;
	void	*step_c;
	void	*game_over;
	void	*cherrie;
	void	*grave;
	void	*player_x;
	void	*player_y;
}	t_wxpm;

// typedef struct player
// {
// 	void	*;
// } p_xpm;

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
char	**map_read(char *path);
void	get_win_dim(t_init *game);
void	put_background(t_init *game, t_wxpm *asset);
void	terrain(void *mlx, t_wxpm *asset);
void	put_border(t_init *game, t_wxpm *asset);
void	put_border2(t_init *game, t_wxpm *asset);
void	put_wall_cherries(t_init *game, t_wxpm *asset);
int		moves_count(int keycode, t_init *game, t_wxpm *asset);
int		ft_exit(void);
void	map_render(t_init *game, t_wxpm *asset);
void	map_update(t_init *game, t_wxpm *asset);

//-----------------------------------------------------//

#endif