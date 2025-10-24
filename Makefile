# -----------------------
# Compiler & Flags
# -----------------------
CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb -O0 -fno-omit-frame-pointer -I. -Ilibft -Iget_next_line -I$(MLX_DIR)

# -----------------------
# Directories & Libraries
# -----------------------
MLX_DIR = /home/nbaidaou/Documents/minilibx-linux-master
LIBFT_DIR = libft
GNL_DIR = get_next_line

LIBFT_LIB = $(LIBFT_DIR)/libft.a
GNL_LIB = $(GNL_DIR)/get_next_line.a
MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm

# -----------------------
# Source & Object Files
# -----------------------
SRC =drawing.c  helpers.c  keypress.c  main.c    map_val_helpers.c  parsing.c    parsing_norm_helpers.c rendering.c  rotate_keypress.c f_free.c   init.c     load_textures.c  main_parsing.c  map_validation.c   parsing_helpers.c  ray_casting.c           rendering_helpers.c
OBJ = $(SRC:.c=.o)

# -----------------------
# Executable Name
# -----------------------
NAME = cub3D

# -----------------------
# Rules
# -----------------------
all: $(NAME)
	@echo "✅ Build successful!"

$(NAME): $(OBJ) $(LIBFT_LIB) $(GNL_LIB) $(MLX_DIR)/libmlx_Linux.a
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(GNL_LIB) $(MLX_LIB) -o $(NAME)

%.o: %.c cub.h
	$(CC) $(CFLAGS) -c $< -o $@

# -----------------------
# Libraries
# -----------------------
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL_LIB):
	$(MAKE) -C $(GNL_DIR)

$(MLX_DIR)/libmlx_Linux.a:
	$(MAKE) -C $(MLX_DIR)

# -----------------------
# Clean rules
# -----------------------
clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean
	@echo "🧹 Cleaned object files!"

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@echo "🗑️ Fully cleaned project!"

re: fclean all

.PHONY: all clean fclean re
