NAME 		= so_long

CC 			= cc
RM			= rm -f
CLONE 		= git clone --depth=1

CFLAGS 		+= -Wall -Wextra -Werror -ggdb
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

LIB_C		= LIB_C

SRC 		= main.c \
			./src/window.c \
			./src/parsing/parsing.c \
			./src/parsing/parsing_1.c \
			./src/parsing/check.c \
			./src/free.c \
			./src/print.c \
			./src/utils/utils.c \
			./src/parsing/flood_fill.c \
			./src/handler/key_handler.c \
			./src/init/init.c \
			./src/init/init_2.c \

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(LIB_C) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) ./LIB_C/LIB_C.a -o $(NAME)  $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	$(CLONE) git@github.com:MiniKlar/MLX42.git $(MLX)
	cmake $(MLX) -B $(MLX)

$(LIB_C):
	$(CLONE) git@github.com:MiniKlar/LIB_C.git LIB_C; cd /home/lomont/42_miniklar/so_long/LIB_C; make; make clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLX)

fclean: clean
	$(RM) -rf $(LIB_C)
	$(RM) -rf $(MLX)
	$(RM) $(NAME)

clear: fclean
	$(RM) -rf $(MLX)

re: fclean all

.PHONY:	all bonus clear clean fclean re
