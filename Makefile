MLX_DIR     = ./src/lib/.mlx
MLX_LIB     = $(MLX_DIR)/libmlx.a
LIBFT_DIR   = ./src/lib/libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
HEADER      = ./src/include/cub3d.h
SRC_DIR     = ./src
OBJ_DIR     = ./obj
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lbsd
SRCS = \
    $(SRC_DIR)/lib/gnl/get_next_line.c \
    $(SRC_DIR)/lib/gnl/get_next_line_utils.c \
    $(SRC_DIR)/lib/malloc/ft_malloc.c \
    $(SRC_DIR)/components/parsing/map_parsing_utile.c \
    $(SRC_DIR)/components/parsing/parsing_errors.c \
    $(SRC_DIR)/components/parsing/map_parsing_utile_2.c \
    $(SRC_DIR)/components/parsing/map_parsing_utile_3.c \
    $(SRC_DIR)/components/parsing/map_parsing_utile_4.c \
    $(SRC_DIR)/components/parsing/map_parsing_utile_5.c \
    $(SRC_DIR)/components/parsing/map_parsing_utile_6.c \
    $(SRC_DIR)/components/parsing/map_parsing_utile_7.c \
    $(SRC_DIR)/components/parsing/map_parsing.c \
    $(SRC_DIR)/main/main.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME = cub3D_Parser

all: $(OBJ_DIR) $(MLX_LIB) $(LIBFT_LIB) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
	@$(MAKE) -s -C $(MLX_DIR)

$(LIBFT_LIB):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)
	@echo "$(NAME) compiled successfully"

clean:
	@$(MAKE) -s -C $(MLX_DIR) clean
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
