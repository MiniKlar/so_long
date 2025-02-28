NAME 			= so_long

CC 				= cc
RM				= rm -f
CLONE 			= git clone --depth=1

CFLAGS 			= -Wall -Wextra -Werror -ggdb
CLINKS			= -ldl -lglfw -pthread -lm

MLX_GIT_URL		= git@github.com:MiniKlar/MLX42.git
MLX				= MLX42
LIBMLX 			= $(MLX)/libmlx42.a

LIB_C_GIT_URL 	= git@github.com:MiniKlar/LIB_C.git
LIB_C			= LIB_C

SRC 			= ./src/main.c \
				./src/handler/window.c \
				./src/parsing/parsing.c \
				./src/parsing/parsing_1.c \
				./src/parsing/check.c \
				./src/parsing/free.c \
				./src/utils/print.c \
				./src/utils/utils.c \
				./src/parsing/flood_fill.c \
				./src/handler/key_handler.c \
				./src/handler/move_player.c \
				./src/init/init.c \
				./src/init/init_2.c \
				./src/init/init_mlx.c \
				./src/handler/change_sprite.c \

OBJ 			= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(MLX) $(LIBMLX) $(LIB_C) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ./LIB_C/LIB_C.a -o $(NAME)  $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	git clone $(MLX_GIT_URL) $(MLX);
	cmake $(MLX) -B $(MLX)

$(LIB_C):
	git clone $(LIB_C_GIT_URL) $(LIB_C)
	$(MAKE) -C $(LIB_C)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(LIB_C)
	$(RM) -r $(MLX)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

clear: fclean
	$(RM) -rf $(MLX)

re: fclean all

.PHONY:	all bonus clear clean fclean re
