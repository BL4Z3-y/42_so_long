# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 11:54:53 by yes-slim          #+#    #+#              #
#    Updated: 2023/01/03 17:14:23 by yes-slim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -fsanitize=undefined
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
LIB = so_long.a
DEL = rm -f

HELPERS = ft_error map_read get_win_dim put_asset image_to_xpm map_render pos_check map_check p_moves
LIBF = ft_strchr ft_strlen ft_strstr ft_strdup ft_strjoin ft_itoa ft_split
GNL = get_next_line
FT_PRINTF =	ft_printf ft_print_char ft_print_str ft_print_nbr ft_print_nbr_uns ft_print_hex_low ft_print_hex_up ft_print_adr

S_HELPERS = $(addsuffix .c, $(addprefix helpers/, $(HELPERS)))
S_LIBFT = $(addsuffix .c, $(addprefix srcs/libft/, $(LIBF)))
S_GNL = $(addsuffix .c, $(addprefix srcs/gnl/, $(GNL)))
S_FT_PRINTF = $(addsuffix .c, $(addprefix srcs/ft_printf/, $(FT_PRINTF)))

SRCS =	$(S_HELPERS) $(S_LIBFT) $(S_GNL) $(S_FT_PRINTF)
		
OBJ =	$(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ) so_long.c
	@ar -rc $(LIB) $(OBJ)
	@echo "YOUR so_long.a IS CREATED"
	@cc so_long.c $(CFLAGS) $(LIB) $(MLX) -o $(NAME)
	@echo "YOUR so_long EXECUTABLE IS CREATED"
	
		
clean :
	@$(DEL) $(OBJ) $(LIB)

fclean : clean
	@$(DEL) $(NAME)

re : fclean all

.PHONY : all clean fclean re
