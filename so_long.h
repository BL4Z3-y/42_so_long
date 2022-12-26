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
	
} init;

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
}	w_xpm;

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
void	get_win_dim(char **str, int *size_h, int *size_w , int *hei, int *wid);
void	put_background(void *mlx, void *win, void *img, int w_hei, int w_wid, int m_wid);
void	image_to_xpm(void *mlx, void **background, void **corner, void **side1, void **side2, void **side3, void **top1, void **top2, void **top3, void **wall);
void	put_border(void *mlx, void *win, void *corner, void *side1, void *side2, void *side3, void *top1, void *top2, void *top3, int hei, int wid);
void	put_border2(void *mlx, void *win, void *side3, void *top3, int hei, int wid);
void	put_wall(void *mlx, void *win, void *wall, char **map, int hei, int wid);
//-----------------------------------------------------//

#endif