#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct image
{
	char	*path;
	int		H;
	int		W;
	void	*img;
} img;

typedef struct initial
{
	void	*mlx;
	void	*win;
	char	**map;
	int		window_h;
	int		window_w;
	
} init;

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
void	get_win_dim(char **str, int *size_h, int *size_w);

//-----------------------------------------------------//

#endif