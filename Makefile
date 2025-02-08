NAME 		= so_long

CC 			= cc
RM			= rm -f
CLONE 		= git clone --depth=1

CFLAGS 		+= -Wall -Wextra -Werror
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

SRC 		= main.c \
			./src/window.c \

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)  $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	$(CLONE) git@github.com:MiniKlar/MLX42.git $(MLX)
	cmake $(MLX) -B $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(MLX)

fclean: clean
	$(RM) $(LIBMLX)
	$(RM) $(NAME)

clear: fclean
	$(RM) -r $(MLX) 

re: fclean all

.PHONY:		all bonus clear clean fclean re